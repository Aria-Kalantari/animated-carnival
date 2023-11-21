from random import randint
from tree import DecisionTree
from tree import Node
import sys

class Pacman:
    def __init__(self, position = tuple(), pinkyPos = tuple(), blinkyPos = tuple, dotPoses = list(), wallPoses = list(), maxDepth = int): 
        self.position = position
        self.pinkyPos = pinkyPos
        self.blinkyPos = blinkyPos
        self.dotPoses = dotPoses
        self.wallPoses = wallPoses
        root = Node(self.position, self.pinkyPos, self.blinkyPos, self.dotPoses, 0, self.wallPoses, 0, 0)
        self.decisionTree = DecisionTree(root, maxDepth)
        self.nextPoses = self.decisionTree.findOptimalPath()
        self.score = 0
        self.countOfEatenDots = 0
        self.countOfMove = 0
        self.pastPos = None
        
    def updateDecisionTree(self, maxDepth):
        root = Node(self.position, self.pinkyPos, self.blinkyPos, self.dotPoses, 0, self.wallPoses, 0, 0)
        self.decisionTree = None
        temp = DecisionTree(root, maxDepth)
        self.decisionTree = temp
        temp = None

    def updateNextPoses(self, maxDepth):
        self.updateDecisionTree(maxDepth)
        self.nextPoses = self.decisionTree.findOptimalPath()
    
    def updatePosition(self):
        self.pastPos = self.position
        self.position = self.nextPoses[0]
        self.nextPoses.pop(0)
    
    def updatePinkyPos(self, pos): 
        self.pinkyPos = pos
    
    def updateBlinkyPos(self, pos): 
        self.BlinkyPos = pos
    
    def updateDotPoses(self):
        if self.position in self.dotPoses:
            self.dotPoses.remove(self.position)
            self.countOfEatenDots += 1

    def updateCountOfMove(self):
        if self.pastPos != self.position:
            self.countOfMove += 1
    
    def updateScore(self):
        return 10 * self.countOfEatenDots - self.countOfMove
    
    def __manhattanDistance(self, a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])

    position = tuple()
    pinkyPos = tuple()
    blinkyPos = tuple()
    wallPoses = list()
    dotPoses = list()
    nextPoses = list()
    countOfEatenDots = int()
    score = int()

################################################################################################################################3

class Ghost:
    def __init__(self, position = tuple(), pacmanPos = tuple(), friendPos = tuple(), wallPoses = list()):
        self.position = position
        self.pacmanPos = pacmanPos
        self.friendPos = friendPos
        self.wallPoses = wallPoses

    def getNextMove(self):
        direction = randint(1, 4)
        if direction == 1: self.nextMove = (1, 0)
        if direction == 2: self.nextMove = (0, 1)
        if direction == 3: self.nextMove = (-1, 0)
        if direction == 4: self.nextMove = (0, -1)
        return self.nextMove
    
    def updatePosition(self):
        self.nextMove = self.getNextMove()
        temp = self.__addToPosition(self.position, self.nextMove)
        if temp not in self.wallPoses and temp not in self.friendPos:
            self.position = temp
    
    def updatePacmanPos(self, pos): 
        self.pacmanPos = pos

    def updateFriendPos(self, pos):
        self.friendPos = pos

    def __addToPosition(self, a, b):  
        return (a[0] + b[0], a[1] + b[1])

    position = tuple()
    pacmanPos = tuple()
    friendPos = tuple()
    wallPoses = list(tuple())
    nextMove = tuple()