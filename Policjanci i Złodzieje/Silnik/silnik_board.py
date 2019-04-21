import random
import numpy as np
import time
import copy
from termcolor import colored
from os import system, name 

# // GLOBAL VARIABLES \\
colorful = 1
N = 20 # board size
T = 100 # max clock ticks
t = 0 # current clock tick
policemanAmount = 5 # amount of policemans on the map
k = 5 # amount of clock ticks in each data exchange between players and the server
timeLimit = 500 # time for the player to calculate the results [ms]
gateAmount = 2 # amount of gates
gateWidth = 2 # gate width
gateMoveChance = 0.5
gateDirectionReversalChance = 0.01
obstacleAmount = 4 # amount of obstacles
obstacleWidth = 4 # obstacle width
obstacleMoveChance = 0.75
obstacleDirectionReversalChance = 0.05
realN = 2*(N+2) + 2*N

class Gate:
  def __init__(self,pos):
    self.direction = random.randint(0,1)
    self.position = pos

  def move(self):
    if random.random() < gateDirectionReversalChance:
      self.direction = 0 if self.direction is 1 else 1

    if random.random() < gateMoveChance:
      for i in range(len(self.position)):
        if self.direction is 0:
          self.position[i] = self.position[i] + 1
          if self.position[i] is realN:
            self.position[i] = 0
        else:
          self.position[i] = self.position[i] - 1
          if self.position[i] < 0:
            self.position[i] = realN - 1


class Wall:
  def __init__(self,coordY,coordX):
    self.position = [coordY,coordX]

class Obstacle:
  def __init__(self,pos,orient):
    self.direction = random.randint(0,3)
    self.position = pos
    self.orientation = orient
  
  def Move(self, thieff, policemanTab):
    if random.random() < obstacleDirectionReversalChance:
      self.direction = random.randint(0,3)

    if random.random() > obstacleMoveChance:
      return

    newPosition = copy.deepcopy(self.position)
    for i in range(obstacleWidth):
      tempPos = copy.deepcopy(newPosition[i])
      #up
      if self.direction == 0:
        if self.position[i][0] == 1:
          self.direction = 2
          return
        
        tempPos[0] = tempPos[0] -1
        if isPlaceFree(tempPos, thieff=thieff, policemanTab=policemanTab) == True:
          newPosition[i] = tempPos
        else:
          return

      #right
      elif self.direction == 1:
        if self.position[i][1] == N:
          self.direction = 3
          return

        tempPos[1] = tempPos[1] + 1
        if isPlaceFree(tempPos, thieff, policemanTab) == True:
          newPosition[i] = tempPos
        else:
          return
      
      #down
      elif self.direction == 2:
        if self.position[i][0] == N:
          self.direction = 0
          return
        tempPos[0] = tempPos[0] + 1
        if isPlaceFree(tempPos, thieff, policemanTab) == True:
          newPosition[i] = tempPos
        else:
          return

      #left
      else:
        if self.position[i][1] == 1:
          self.direction = 1
          return
        tempPos[1] = tempPos[1] - 1
        if isPlaceFree(tempPos, thieff, policemanTab) == True:
          newPosition[i] = tempPos
        else:
          return
    self.position = newPosition

        



class Thief:
  def __init__(self,coords):
    self.position = coords

  def move(self, direction):
    if direction is 0:
      return

    requestedPosition = copy.deepcopy(self.position)
    if direction is 1:
      requestedPosition[0] -= 1
    elif direction is 2:
      requestedPosition[1] += 1
    elif direction is 3:
      requestedPosition[0] += 1
    elif direction is 4:
      requestedPosition[1] -= 1

    # if the new position is goes to the gate, we can accept that without any further investigation
    for gate in gateTab:
      for i in range(len(gate.position)):
        if requestedPosition[0] is wallTab[gate.position[i]].position[0] and requestedPosition[1] is wallTab[gate.position[i]].position[1]:
          self.position = requestedPosition
          return

    # checking if policeman didn't hit the wall/enter the gate
    if requestedPosition[0] < 1 or requestedPosition[0] > N or requestedPosition[1] < 1 or requestedPosition[1] > N:
      return

    if isPlaceFree(requestedPosition, obstacleTab=obstacleTab):
      self.position = requestedPosition



class Policeman:
  def __init__(self,coords, ID):
    self.position = coords
    self.ID = ID

  def move(self, direction):
    if direction is 0:
      return

    requestedPosition = copy.deepcopy(self.position)
    if direction is 1:
      requestedPosition[0] -= 1
    elif direction is 2:
      requestedPosition[1] += 1
    elif direction is 3:
      requestedPosition[0] += 1
    elif direction is 4:
      requestedPosition[1] -= 1

    # checking if policeman didn't hit the wall/enter the gate
    if requestedPosition[0] < 1 or requestedPosition[0] > N or requestedPosition[1] < 1 or requestedPosition[1] > N:
      return

    if isPlaceFree(requestedPosition, obstacleTab=obstacleTab):
      self.position = requestedPosition

gateTab = []
wallTab = []
obstacleTab = []
policemanTab = []
thiefu = Thief([0,0])

def checkWinningConditions():
  # firstly, we check if the thief has escaped
  for gate in gateTab:
    for i in range(len(gate.position)):
      if thiefu.position[0] is wallTab[gate.position[i]].position[0] and thiefu.position[1] is wallTab[gate.position[i]].position[1]:
        return 0, (2*T - t - 1)

  # next, we check if the policemans have captured the thief
  for policeman in policemanTab:
    # creating a surroundings, where the policeman can catch the thief
    tempPos = copy.deepcopy(policeman.position)
    catchField = [copy.deepcopy(tempPos)]
    tempPos[0] += 1
    catchField.append(copy.deepcopy(tempPos))
    tempPos[0] -= 2
    catchField.append(copy.deepcopy(tempPos))
    tempPos[0] += 1
    tempPos[1] += 1
    catchField.append(copy.deepcopy(tempPos))
    tempPos[1] -= 2
    catchField.append(copy.deepcopy(tempPos))

    for catchCoords in catchField:
      if thiefu.position[0] is catchCoords[0] and thiefu.position[1] is catchCoords[1]:
        return 1, t

  # lastly, the time might have expired
  if t is T-1:
    return 0, T

  # ... there battle might not have been settled either
  return -1, -1

def InitBoard():
  global thiefu
  #creating walls - circled layout in order to easily handle gates movement
  for i in range(N+2):
    wallTab.append(Wall(i,0))
  for i in range(1,N+1):
    wallTab.append(Wall(N+1,i))
  for i in range(N+1,0,-1):
    wallTab.append(Wall(i,N+1))
  for i in range(N+1,0,-1):
    wallTab.append(Wall(0,i))

  # creating gates
  for i in range(gateAmount):
    newGateCoord = findPlaceForGate(gateTab)
    gateTab.append(Gate(newGateCoord))

  # creating obstacles
  for i in range(obstacleAmount):
    newObstacleOrientation = random.randint(0,1)
    newObstacleCoords = findPlaceForObstacle(obstacleTab, newObstacleOrientation)
    obstacleTab.append(Obstacle(newObstacleCoords,newObstacleOrientation))

  # creating a policemans
  ite = policemanAmount
  while ite > 0:
    ite = ite - 1
    policeCoords = [random.randint(1,N-2), random.randint(1,N-2)]
    while isPlaceFree(policeCoords, policemanTab=policemanTab, obstacleTab=obstacleTab) is False:
      policeCoords = [random.randint(1,N-2), random.randint(1,N-2)]
    #creating new policeman. Second argument is policeman's unique ID - thus, I add some value (20) to make them stand out
    policemanTab.append(Policeman(policeCoords, ite + 5))

  # creating a thief
  thiefCoords = [random.randint(1,N-2), random.randint(1,N-2)]
  thiefu = Thief(thiefCoords)
  while isPlaceFree(thiefCoords, obstacleTab=obstacleTab, policemanTab=policemanTab, policemanLapki=True) is False:
    thiefu.position = [random.randint(1,N-2), random.randint(1,N-2)]

  # return constructBoard(wallTab, gateTab, obstacleTab, thiefu, policemanTab)
  finalDict = getBoardStateDictionary()
  return finalDict

  # temporary game loop
  # while True:
  #   constructBoard(wallTab, gateTab, obstacleTab, thiefu, policemanTab, True)
  #   time.sleep(0.5)
  #   for gate in gateTab:
  #     gate.move()
  #   for obst in obstacleTab:
  #     obst.Move(thiefu, policemanTab)

# gateTab = []
# wallTab = []
# obstacleTab = []
# policemanTab = []
# thiefu = None

# retrieves all the objects' coordinates and stores them as a dictionary of arrays
def getBoardStateDictionary():
  gatesCoords = []
  for gate in gateTab:
    singleGate = []
    for i in gate.position:
      coords = wallTab[i].position
      singleGate.append(coords)
    gatesCoords.append(singleGate)

  obstaclesCoords = []
  for obstacle in obstacleTab:
    obstaclesCoords.append(obstacle.position)

  policemansCoords = []
  policemansID = []
  for policeman in policemanTab:
    policemansCoords.append(policeman.position)
    policemansID.append(policeman.ID)

  #building dictionary

  boardDictionary = {
    'gatesCoords': gatesCoords,
    'obstaclesCoords': obstaclesCoords,
    'thiefCoords': thiefu.position
  }
  for i,policeman in enumerate(policemanTab):
    boardDictionary['policeman' + str(i+1)] = {
      'ID': policeman.ID,
      'coords': policeman.position
    }

  return boardDictionary


def findPlaceForGate(gateTab):
  # Finding first new spot
  gatePos = random.randint(0,realN-1)
  while isFarEnough(gatePos, gateTab) is False:
    gatePos = random.randint(0,realN-1)

  newGateTab = [gatePos]
  if gateWidth < 2:
    return newGateTab
  
  ite = 0
  while ite < gateWidth-1:
    gatePos = newGateTab[ite] - 1
    if gatePos < 0:
      gatePos = realN-1
    newGateTab.append(gatePos)
    ite = ite + 1
  return newGateTab

def findPlaceForObstacle(obstacleTab, obstacleOrientation):
  coordY = 0
  coordX = 0
  while True:
    if obstacleOrientation == 0:
      coordY = random.randint(1,N-2)
      coordX = random.randint(1,N-obstacleWidth-2)
      for i in range(obstacleWidth):
        if isPlaceFree([coordY,coordX+i], obstacleTab=obstacleTab) is False:
          continue
    else:
      coordY = random.randint(1,N-obstacleWidth-2)
      coordX = random.randint(1,N-2)
      for i in range(obstacleWidth):
        if isPlaceFree([coordY+i,coordX], obstacleTab=obstacleTab) is False:
          continue

    break
  
  tab = []
  for i in range(obstacleWidth):
    if obstacleOrientation == 0:
      tab.append([coordY,coordX+i])
    else:
      tab.append([coordY+i,coordX])

  return tab



def isFarEnough(x, gateTab):
  ite = gateWidth
  while ite > -1:
    ite = ite - 1
    for gatee in gateTab:
      for i in range(len(gatee.position)):
        if x == gatee.position[i]:
          return False
    x = x - 1
    if x < 0:
      x = realN-1
  return True

def isPlaceFree(coords, thieff=False, policemanTab=False, obstacleTab=False, policemanLapki=False):
  if thieff is not False:
    if isEqual(coords, thieff.position):
      return False

  if policemanTab is not False:
    for police in policemanTab:
      if isEqual(coords, police.position):
        return False

  if policemanLapki is not False:
    for police in policemanTab:
      # creating a surroundings, where the policeman can catch the thief
      tempPos = copy.deepcopy(police.position)
      catchField = [copy.deepcopy(tempPos)]
      tempPos[0] += 1
      catchField.append(copy.deepcopy(tempPos))
      tempPos[0] -= 2
      catchField.append(copy.deepcopy(tempPos))
      tempPos[0] += 1
      tempPos[1] += 1
      catchField.append(copy.deepcopy(tempPos))
      tempPos[1] -= 2
      catchField.append(copy.deepcopy(tempPos))

      for catchCoords in catchField:
        if coords[0] is catchCoords[0] and coords[1] is catchCoords[1]:
          return False
  
  if obstacleTab is not False:
    for obst in obstacleTab:
      for j in range(len(obst.position)):
        if isEqual(coords, obst.position[j]):
          return False

  return True

def isEqual(A,B):
  if A[0] == B[0] and A[1] == B[1]:
    return True
  return False

def constructBoard(wallTab, gateTab, obstacleTab, thieff, policemanTab, draw=False):
  board = np.zeros([N+2,N+2])
  for wall in wallTab:
    board[wall.position[0],wall.position[1]] = 1

  for gate in gateTab:
    for i in gate.position:
      coords = wallTab[i].position
      board[coords[0], coords[1]] = 2

  for obst in obstacleTab:
    for i in range(len(obst.position)):
      coords = obst.position[i]
      board[coords[0], coords[1]] = 3

  board[thieff.position[0], thieff.position[1]] = 4

  for pol in policemanTab:
    board[pol.position[0], pol.position[1]] = pol.ID

  if draw == True:
    if colorful == 1:
      printColorful(board)
    else:
      print(board)
      print('')

  return board

def printColorful(board):
  _ = system('cls')
  toPrint = ''
  for i in range(len(board)):
    for j in range(len(board)):
      x = int(board[i][j])
      if x == 0:
        toPrint = toPrint + ' ' + colored(str(x), 'grey') + ' '
      elif x == 1:
        toPrint = toPrint  + ' ' + colored(str(x), 'white') + ' '
      elif x == 2:
          toPrint = toPrint + ' ' + colored(str(x), 'cyan') + ' '
      elif x == 3:
          toPrint = toPrint + ' ' + colored(str(x), 'green') + ' '
      elif x == 4:
          toPrint = toPrint + ' ' + colored(str(x), 'red') + ' '
      else:
          toPrint = toPrint + ' ' + colored(str(x), 'blue') + ' '
    toPrint = toPrint + '\n'
  print(toPrint)
  print('')