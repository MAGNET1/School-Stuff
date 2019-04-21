import socket, time, json
import silnik_socket
import silnik_board
import random
  
# import thread module 
from _thread import *
import threading 

sharedInfo = {
  'threadsResponded': 0, # used for communication with threads, that handle socket connection. If this value equals 2, it is a signal for main that there is a respond from both players
  'ctThread': False,
  'ttThread': False,
  'gameOver': False,
  'winner': -1,
  'score': -1,
  'usersConnected': 0,
  'ttName': 'Brak',
  'ctName': 'Brak',
  'ttSequence': dict(),
  'ctSequence': dict(),
  'board0': None,
}
  
  
def Main(): 
  start_new_thread(t_Main, ()) 

def t_Main():
  lock = threading.Lock()
  host = "" 
  
  port = 12347
  s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
  s.bind((host, port)) 

  s.listen(5) 
  print("Serwer uruchomiony! Oczekiwanie na graczy...") 

  while True: 

      c, addr = s.accept() 

      # print('Connected to :', addr[0], ':', addr[1]) 

      # Start a new thread and return its identifier 
      start_new_thread(silnik_socket.tInitConnection, (c,sharedInfo, lock)) 
  s.close() 
  
  
if __name__ == '__main__':
  # running thread, that listens for new clients
  Main()


  # we pause the main thread and wait till both players will connect
  while sharedInfo['usersConnected'] != 2:
    time.sleep(0.2)
  
  currentBoard = silnik_board.InitBoard()
  # everyone has connected. Now we can generate the board and send it to the players
  sharedInfo['board0'] = currentBoard
  sharedInfo['ttThread'] = True
  sharedInfo['ctThread'] = True

  silnik_board.constructBoard(silnik_board.wallTab, silnik_board.gateTab, silnik_board.obstacleTab, silnik_board.thiefu, silnik_board.policemanTab, True)

  '''#### MAIN LOOP ####'''
  while True:
    # First, we wait for both player sequences in sharedInfo to be filled...
    while sharedInfo['ttThread'] is True or sharedInfo['ctThread'] is True:
      time.sleep(0.2) ## TUTAJ CZEKAŁEM!!!!!!!!!!!!!!!!!!!!

    ttSequence = sharedInfo['ttSequence']['sequence']
    ctSequence = []
    for i in range(silnik_board.policemanAmount):
      ctSequence.append(sharedInfo['ctSequence']['policeman' + str(silnik_board.policemanAmount - i)])


    for i in range(silnik_board.k):
      time.sleep(1.0)
      silnik_board.t += 1
      # Secondly, we save the current state to the history in shared memory
      sharedInfo['board' + str(silnik_board.k - i - 1)] = currentBoard

      # Next, we move gates and obstacles
      for gate in silnik_board.gateTab:
        gate.move()
      for obst in silnik_board.obstacleTab:
        obst.Move(silnik_board.thiefu, silnik_board.policemanTab)
        
      # Time for the players
      silnik_board.thiefu.move(ttSequence[i])
      # silnik_board.thiefu.move(random.randint(0,5))

      for policemanMove in ctSequence:
        currentPolicemanSequence = policemanMove['sequence']
        for j in range(silnik_board.policemanAmount):
          if silnik_board.policemanTab[j].ID is policemanMove['ID']:
            silnik_board.policemanTab[j].move(currentPolicemanSequence[i])
            # silnik_board.policemanTab[j].move(random.randint(0,5))
            # print(j)

      silnik_board.constructBoard(silnik_board.wallTab, silnik_board.gateTab, silnik_board.obstacleTab, silnik_board.thiefu, silnik_board.policemanTab, True)
      currentBoard = silnik_board.getBoardStateDictionary()
      boardResult = silnik_board.checkWinningConditions()
      if boardResult[0] != -1:
        print('GAME OVER!')
        sharedInfo['gameOver'] = 1
        sharedInfo['winner'] = boardResult[0]
        sharedInfo['score'] = boardResult[1]
        sharedInfo['ttThread'] = True
        sharedInfo['ctThread'] = True
        sharedInfo['mainThread'] = False
        print(boardResult)
        time.sleep(2.0)
        quit()
  
    # here, all the k moves has been done. It's time to send the result to the players and wait for new set of moves
    sharedInfo['ttThread'] = True
    sharedInfo['ctThread'] = True
    
    # silnik_board.InitBoard()