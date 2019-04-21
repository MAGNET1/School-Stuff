# Import socket module 
import socket, json, time
  
# print('Received from the server :',str(data.decode('utf8')))

def Main(): 
    # here we fill all the required informations
    host = '127.0.0.1' # If fighting locally, this IP shall remain unchanged
    port = 12347 # some port on which the connection will be established
    mode = 0 # team identifier. 0 - zlodziej, 1 - policjanci
    nazwa = 'Lara Croft' # name of your team :)
  

    # first step - we attempt connecting to the server
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM) 
    s.connect((host,port))

    #preparing an init message (as JSON)
    message = json.dumps({
        "type": "init",
        "team": mode,
        "name": nazwa
    }).encode('utf8')
  
    # message sent to server 
    s.send(message) 

    # message received from server  - it indicates whether or not we are in the game
    data = s.recv(4096) 

    # we parse the JSON - from now on, y is a simple dictionary
    y = json.loads(data)

    if y['status'] == 'ERROR':
        print('Nie udało się nawiązać połączenia! Błąd: ' + y['message'])
        s.close()
        return
    else:
        print('Połączenie udane! Oczekiwanie na drugiego gracza...')

        # we send some message, indicating that we are waiting for another player...
        message = json.dumps({
            "type": "waiting",
        }).encode('utf8')
        s.send(message)

        # ... now we wait for a while up to the point, where both players will be succesfully connected to the server

        # this is the main game loop. Will continue to communicate with the server until 'gameOver' message is sent
        # also, keep in mind that when server sends the FIRST board, there are no time restrictions. After that, u r limited to 500ms in each cycle
        while True:
            # this message contains the board informations. For now, I simply print them on the screen
            data = s.recv(4096)
            print('Received from the server :',str(data.decode('utf8')))

            # we convert the data to a simple dictionary
            serverBoard = json.loads(data)

            # there might be some error. Thus, we shall check what exactly went wrong...
            if serverBoard['status'] is 'ERROR':
                print('Server error! Message: ' + serverBoard['message'])
                return

            # next, we make sure the game hasn't ended:
            if serverBoard['status'] is 'gameOver':
                print('Game over! Winner: ' + str(serverBoard['winner']) + ', score: ' + str(serverBoard['score']))
                return

            # if none of the conditions above were triggered, you can start processing your board...


            ###############
            ## this is the point, where you should do all the required calculations. There's no hurry - u can process it for as long as u wish to for the 1st time
            ###############

            # ..... 

            # are u done already? Ok, what you should end up with is a dictionary. Something as follows:

            yourMove = json.dumps({
                'type': 'playerMove',
                'sequence': [1,2,3,4,0]
            }).encode('utf8')

            # next, you simply send it. After that, the loop will start over and wait for incoming boards
            s.send(yourMove)

  
if __name__ == '__main__': 
    Main() 