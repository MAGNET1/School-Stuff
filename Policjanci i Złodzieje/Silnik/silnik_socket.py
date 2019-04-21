import socket, time, json
import silnik_main
import silnik_board
import time
import os

# thread fuction 
def tInitConnection(c, info, lock):
  """
  Handles the connection
  """
  while True: 

    # data received from client 
    data = c.recv(1024)

    if len(data) == 0:
      print('Socket has disconnected! usersConnected: ' + str(info["usersConnected"]))
      c.close()
      break

    if not data:
      c.send(json.dumps({"status": "ERROR", "message": "Pusta wiadomosc! Polaczenie przerwane"}).encode('utf8'))
      c.close()
      break
      
    y = json.loads(data)

    if 'type' not in y:
      c.send(json.dumps({"status": "ERROR", "message": "Niewlasciwy format wiadomosci! Polaczenie przerwane"}).encode('utf8'))
      c.close()
      break

    if y['type'] != 'init':
      if info["ttID"] == 0 or info["ctID"] == 0:
        c.send(json.dumps({"status": "ERROR", "message": "Nie wszyscy gracze sa w grze! Polaczenie przerwane"}).encode('utf8'))
        c.close()
        break
    else:
      if 'team' not in y:
        c.send(json.dumps({"status": "ERROR", "message": "Nie okreslono druzyny! Polaczenie przerwane"}).encode('utf8'))
        c.close()
        break

      if y['team'] > 1 or y['team'] < 0:
        c.send(json.dumps({"status": "ERROR", "message": "Niepoprawny identyfikator! (0 - zlodziej, 1 - policjanci). Polaczenie przerwane"}).encode('utf8'))
        c.close()
        break

      if y['team'] == 0:
        if info['ttName'] != 'Brak':
          c.send(json.dumps({"status": "ERROR", "message": "Do gry podlaczyl sie juz zlodziej! Polaczenie przerwane"}).encode('utf8'))
          c.close()
          break
        else:
          c.send(json.dumps({"status": "OK", "message": "Witaj, zlodzieju!"}).encode('utf8'))
          info["usersConnected"] += 1
          info["ttName"] = y['name']
          print('Do gry dolaczyl zlodziej! Nazwa: ' + info["ttName"])
          data = c.recv(1024)
          while info["board0"] is None:
            time.sleep(0.2)
          # at this point, both players have succesfully connected and there's a board for them to be sent
          tSendFirstBoard(c, info, 'tt', lock)
          

      elif y['team'] == 1:
        if info['ctName'] != 'Brak':
          c.send(json.dumps({"status": "ERROR", "message": "Do gry podlaczyli juz policjanci! Polaczenie przerwane"}).encode('utf8'))
          c.close()
          break
        else:
          c.send(json.dumps({"status": "OK", "message": "Witajcie, policjanci!"}).encode('utf8'))
          info["usersConnected"] += 1
          info["ctName"] = y['name']
          print('Do gry dolaczyli policjanci! Nazwa: ' + info["ctName"])
          data = c.recv(1024)
          while info["board0"] is None:
            time.sleep(0.2)
          # at this point, both players have succesfully connected and there's a board for them to be sent
          tSendFirstBoard(c, info, 'ct', lock)

  # connection closed 
  c.close() 
  
  
def tSendFirstBoard(c, info, team, lock):

  # building JSON with all the required informations...
  initMessage = json.dumps({
    "status": "boardInit",
    "board": info["board0"],
    "boardSize": silnik_board.N,
    "amountOfPolicemans": silnik_board.policemanAmount,
    "clockMaxTicks": silnik_board.T,
    "clockSingleRoundTicks": silnik_board.k,
    "timeLimit": silnik_board.timeLimit,
    "gateAmount": silnik_board.gateAmount,
    "gateWidth": silnik_board.gateWidth,
    "gateMoveChance": silnik_board.gateMoveChance,
    "gateDirectionReversalChance": silnik_board.gateDirectionReversalChance,
    "obstacleAmount": silnik_board.obstacleAmount,
    "obstacleWidth": silnik_board.obstacleWidth,
    "obstacleMoveChance": silnik_board.obstacleMoveChance,
    "obstacleDirectionReversalChance": silnik_board.obstacleDirectionReversalChance
  }).encode('utf8')
  c.send(initMessage)

  # we don't measure the time in a first take
  data = c.recv(1024)
  playerMove = json.loads(data)
  validityResult, message = isPlayerMoveDictionaryStructureValid(playerMove, team)

  if validityResult is False:
    print('Gracz ' + str(team) + ' wysłał niepoprawną pierwszą wiadomość! Przerywam program... [' + message + ']')
    c.send(json.dumps({"status": "ERROR", "message": message}).encode('utf8'))
    c.close()
    os._exit(1)

  info[team + 'Sequence'] = playerMove

  lock.acquire()
  try:
    info[str(team) + 'Thread'] = False
  finally:
    lock.release()

  # now, we move straight to the normal game
  tPlayerLoop(c, info, team, lock)


def tPlayerLoop(c, info, team, lock):
  while True:
    # first, we wait for the main thread to finish all the moves. After it's done, 'ct(tt)Thread' will we reset
    while info[str(team) + 'Thread'] is False:
      time.sleep(0.2)

    # print(str(team) + 'siema!')

    if info['gameOver'] is 1:
      gameOverMessage = json.dumps({
        'status': 'gameOver',
        'winner': info['winner'],
        'score': info['score']
      }).encode('utf8')
      c.send(gameOverMessage)
      time.sleep(2.0)
      c.close()
      return

    # we create new board to be sent
    nextStateMessageDict = {
      'status': 'inProgress',
    }
    
    # we add all the board states...
    for key, value in info.items():
      if 'board' in key:
        nextStateMessageDict[str(key)] = str(value)

    nextStateMessage = json.dumps(nextStateMessageDict).encode('utf8')

    c.send(nextStateMessage)

    # we measure the time and check if it hasn't exceeded the maximum of 500ms
    timeBegin = time.time()
    data = None
    data = c.recv(1024)
    timeEnd = time.time()

    playerMove = json.loads(data)
    validityResult, message = isPlayerMoveDictionaryStructureValid(playerMove, team)

    # if too late - we make all the moves empty
    if timeEnd - timeBegin > 0.5 or validityResult is False:
      # soorry for that unnecessary double-check ;/
      if validityResult is False:
        print('Błąd w słowniku gracza ' + str(team) + '! Error: ' + message)
      # same here...
      if timeEnd - timeBegin > 0.5:
        print('Gracz ' + team + ' nie zdążył wysłać wiadomości w czasie 500ms!')

      if team is 'tt':
        ttSequence = playerMove['sequence']
        for i in range(silnik_board.k):
          ttSequence[i] = 0
        playerMove['sequence'] = ttSequence
      else:
        for i in range(silnik_board.policemanAmount):
          ctSequence = playerMove['policeman' + str(silnik_board.policemanAmount - i)]['sequence']
          for j in range(len(ctSequence)):
            ctSequence[j] = 0
          ctSequence = playerMove['policeman' + str(silnik_board.policemanAmount - i)]['sequence'] = ctSequence

    info[team + 'Sequence'] = playerMove

    
    lock.acquire()
    try:
      info[str(team) + 'Thread'] = False
    finally:
      lock.release()
    

def isPlayerMoveDictionaryStructureValid(jsonFile, team):
  if team is 'tt':
    if 'type' not in jsonFile or 'sequence' not in jsonFile:
      return False, 'Niepoprawny format wiadomości! Sprawdz strukture przykladowego clienta zlodzieja! (silnikZlodziej.py)'

    sequence = jsonFile['sequence']
    if len(sequence) is not silnik_board.k:
      return False, 'Niewlasciwa ilosc ruchow! (wymagane: ' + str(silnik_board.k) + ')'

    amountOfKeys = 0
    for key in jsonFile.keys():
      amountOfKeys += 1
    if amountOfKeys is not 2:
      return False, 'Niepoprawna ilość kluczy w słowniku! Sprawdz strukture przykladowego clienta zlodzieja! (silnikZlodziej.py)'

  elif team is 'ct':
    if 'type' not in jsonFile:
      return False, 'Niepoprawny format wiadomości! Sprawdz strukture przykladowego clienta policjanta! (silnikPolicjant.py)'

    amountOfKeys = 0
    for key in jsonFile.keys():
      amountOfKeys += 1
      if 'type' not in key and 'policeman' not in key:
        return False, 'Niepoprawny format wiadomości! Sprawdz strukture przykladowego clienta policjanta! (silnikPolicjant.py)'

      if 'policeman' in key and (int(key[-1:]) < 1 or int(key[-1:]) > silnik_board.policemanAmount):
        return False, 'Niepoprawna nazwa policjanta! Wszyscy powinni nazywac się kolejno: policeman1, policeman2 etc...'
    
    if amountOfKeys is not silnik_board.policemanAmount+1:
      return False, 'Niepoprawna ilość kluczy w słowniku! Sprawdz strukture przykladowego clienta policjanta! (silnikPolicjant.py)'

    for i in range(amountOfKeys-1):
      if jsonFile['policeman' + str(i+1)]['ID'] < 5 or jsonFile['policeman' + str(i+1)]['ID'] > 4 + silnik_board.policemanAmount:
        return False, 'Niepoprawne ID policjanta nr ' + str(i+1) + '! ID powinno zaczynać się od 5 i rosnąć o 1 co każdego policjanta'

      if len(jsonFile['policeman' + str(i+1)]['sequence']) is not silnik_board.k:
        return False, 'Niewlasciwa ilosc ruchow! (wymagane: ' + str(silnik_board.k) + ')'

  return True, ''