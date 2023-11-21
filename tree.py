import sys

class Node:
    def __init__(self, pacmanPos = tuple(), pinkyPos = tuple(), blinkyPos = tuple(), dotPoses = list(), countOfDotsEaten = int(), wallPoses = list(), countOfMovesOfPacman = int(), depth = int()):
        self.pacmanPos = pacmanPos
        self.pinkyPos = pinkyPos
        self.blinkyPos = blinkyPos
        self.dotPoses = dotPoses
        self.countOfDotsEaten = countOfDotsEaten
        self.wallPoses = wallPoses
        self.countOfMovesOfPacman = countOfMovesOfPacman
        self.depth = depth
        self.children = []
        self.father = None

        pacmanPos = tuple()
        pinkyPos = tuple()
        blinkyPos = tuple()
        dotPoses = list()
        countOfDotsEaten = int()
        countOfMovesOfPacman = int()
        wallPoses = list()
        depth = int()
        
class DecisionTree:
    def __init__(self, root = Node(), maxDepth = int()):
        self.root = root
        self.maxDepth = maxDepth
        self.leaves = []
        self.buildTree()
    
    def buildTree(self):
        queue = list()
        node = self.root
        queue.append(node)   

        while not len(queue) == 0:
            node = queue.pop(0)
            
            direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]

            if node.depth % 3 == 0:
                for i in range(0, 4):
                    childPacmanPos = self.__addToPositionForPacman(node.pacmanPos, direction[i], node.wallPoses)
                    childPinkyPos = node.pinkyPos
                    childBlinkyPos = node.blinkyPos
                    if childPacmanPos in node.dotPoses:
                        childDotPoses = node.dotPoses.copy()
                        childDotPoses.remove(childPacmanPos)
                        childCountOfDotsEaten = node.countOfDotsEaten + 1
                    else:
                        childDotPoses = node.dotPoses.copy()
                        childCountOfDotsEaten = node.countOfDotsEaten
                    childWallPoses = node.wallPoses.copy()
                    if childPacmanPos != node.pacmanPos:
                        childCountOfMovesOfPacman = node.countOfMovesOfPacman + 1
                    else:
                        childCountOfMovesOfPacman = node.countOfMovesOfPacman
                    childDepth = node.depth + 1
                    child = Node(childPacmanPos, childPinkyPos, childBlinkyPos, childDotPoses, childCountOfDotsEaten, childWallPoses, childCountOfMovesOfPacman, childDepth)
                    child.father = node
                    node.children.append(child)
            
            elif node.depth % 3 == 1:
                for i in range(0, 4):
                    childPacmanPos = node.pacmanPos
                    childPinkyPos = self.__addToPositionForGhosts(node.pinkyPos, direction[i], childBlinkyPos, node.wallPoses)
                    childBlinkyPos = node.blinkyPos
                    childDotPoses = node.dotPoses.copy()
                    childCountOfDotsEaten = node.countOfDotsEaten
                    childWallPoses = node.wallPoses.copy()
                    childCountOfMovesOfPacman = node.countOfMovesOfPacman
                    childDepth = node.depth + 1
                    child = Node(childPacmanPos, childPinkyPos, childBlinkyPos, childDotPoses, childCountOfDotsEaten, childWallPoses, childCountOfMovesOfPacman, childDepth)
                    child.father = node
                    node.children.append(child)
            
            elif node.depth % 3 == 2:
                for i in range(0, 4):
                    childPacmanPos = node.pacmanPos
                    childPinkyPos = node.pinkyPos
                    childBlinkyPos = self.__addToPositionForGhosts(node.blinkyPos, direction[i], childPinkyPos, node.wallPoses)
                    childDotPoses = node.dotPoses.copy()
                    childCountOfDotsEaten = node.countOfDotsEaten
                    childWallPoses = node.wallPoses.copy()
                    childCountOfMovesOfPacman = node.countOfMovesOfPacman
                    childDepth = node.depth + 1
                    child = Node(childPacmanPos, childPinkyPos, childBlinkyPos, childDotPoses, childCountOfDotsEaten, childWallPoses, childCountOfMovesOfPacman, childDepth)
                    child.father = node
                    node.children.append(child)
            
            if node.children[3].depth != self.maxDepth:
                for i in range(0, 4):
                    queue.append(node.children[i])
            else:
                for i in range(0, 4):
                    self.leaves.append(node.children[i])
        self.eUtility()

    def eUtility(self):
        for leaf in self.leaves:
            pacmanPos = leaf.pacmanPos
            pinkyPos = leaf.pinkyPos
            blinkyPos = leaf.blinkyPos

            dotPoses = leaf.dotPoses
            dotCount = len(dotPoses)
            closestDot = 1

            g = 10 * leaf.countOfDotsEaten - leaf.countOfMovesOfPacman

            dotDistances = [self.__manhattanDistance(pacmanPos, dotPos) for dotPos in dotPoses]

            if dotCount > 0:
                closestDot = min(dotDistances)
            distanceToClosestGhost = min(self.__manhattanDistance(pacmanPos, pinkyPos), self.__manhattanDistance(pacmanPos, blinkyPos))
            if distanceToClosestGhost < 2:
                closestDot = 99999

            features = [1.0 / closestDot, g]
            weights = [10, 200]
            self.utilities[leaf] = sum([feature * weight for feature, weight in zip(features, weights)])

    def _minimax(self, node, alpha, beta):
        if node.depth == self.maxDepth:
            return self.utilities[node], node
        if node.depth % 3 == 0:
            utility = -sys.maxsize
            for child in node.children:
                newUtility, newNode = self._minimax(child, alpha, beta)
                if newUtility > utility:
                    utility = newUtility
                    optimalNode = newNode
                alpha = max(alpha, utility)
                if beta <= alpha:
                    break
            return utility, optimalNode
        else:
            utility = sys.maxsize
            for child in node.children:
                newUtility, newNode = self._minimax(child, alpha, beta)
                if newUtility < utility:
                    utility = newUtility
                    optimalNode = newNode
                beta = min(beta, utility)
                if beta <= alpha:
                    break
            return utility, optimalNode

    def alphaBetaPruning(self):
        alpha = -sys.maxsize
        beta = sys.maxsize
        utility, optimalNode = self._minimax(self.root, alpha, beta)
        return utility, optimalNode

    def findOptimalPath(self):
        _, optimalNode = self.alphaBetaPruning()
        maximizingPlayerPoses = []
        node = optimalNode
        while node.father is not None:
            if node.depth % 3 == 0:
                maximizingPlayerPoses.append(node.pacmanPos)
            node = node.father
        maximizingPlayerPoses.reverse()
        return maximizingPlayerPoses

    def __addToPositionForPacman(self, a, b, wallPoses):
        if (a[0] + b[0], a[1] + b[1]) in wallPoses:
            return a
        else:
            return (a[0] + b[0], a[1] + b[1])
    
    def __addToPositionForGhosts(self, a, b, friendPos, wallPoses):
        if (a[0] + b[0], a[1] + b[1]) in wallPoses or (a[0] + b[0], a[1] + b[1]) == friendPos:
            return a
        else:
            return (a[0] + b[0], a[1] + b[1])

    def __manhattanDistance(self, a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])

    root = Node(tuple(), tuple(), tuple(), list(), list(), int())
    maxDepth = int()
    leaves = list()
    utilities = dict()