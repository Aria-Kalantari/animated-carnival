from game import Game
import os
from time import sleep

pacmanPos = (9, 1)
pinkyPos = (11, 3)
blinkyPos = (16, 7)
dotPoses = [(1, 1), (2, 1), (3, 1), (4, 1), (6, 1), (7, 1), (8, 1), (10, 1), (11, 1), (12, 1), (13, 1), (15, 1), (16, 1), (17, 1), (18, 1),
            (1, 2), (4, 2), (6, 2), (13, 2), (15, 2), (18, 2),
            (1, 3), (3, 3), (4, 3), (5, 3), (6, 3), (7, 3), (8, 3), (9, 3), (10, 3), (12, 3), (13, 3), (14, 3) ,(15, 3), (16, 3), (18, 3),
            (1, 4), (3, 4), (6, 4), (13, 4), (16, 4), (18, 4),
            (1, 5), (2, 5), (3, 5), (4, 5), (5, 5), (6, 5), (13, 5), (14, 5), (15, 5), (16, 5), (17, 5), (18, 5),
            (1, 6), (3, 6), (6, 6), (13, 6), (16, 6), (18, 6),
            (1, 7), (3, 7), (4, 7), (5, 7), (6, 7), (7, 7), (8, 7), (9, 7), (10, 7), (11, 7), (12, 7), (13, 7), (14, 7) ,(15, 7), (18, 7),
            (1, 8), (4, 8), (6, 8), (13, 8), (15, 8), (18, 8),
            (1, 9), (2, 9), (3, 9), (4, 9), (6, 9), (7, 9), (8, 9), (9, 9), (10, 9), (11, 9), (12, 9), (13, 9), (15, 9), (16, 9), (17, 9), (18, 9)]
wallPoses = [(0, 0), (1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0), (7, 0), (8, 0), (9, 0), (10, 0), (11, 0), (12, 0), (13, 0), (14, 0), (15, 0), (16, 0), (17, 0), (18, 0), (19, 0),
             (0, 1), (5, 1), (14, 1), (19, 1),
             (0, 2), (2, 2), (3, 2), (5, 2), (7, 2), (8, 2), (9, 2), (10, 2), (11, 2), (12, 2), (14, 2), (16, 2), (17, 2), (19, 2),
             (0, 3), (2, 3), (17, 3), (19, 3),
             (0, 4), (2, 4), (4, 4), (5, 4), (7, 4), (8, 4), (9, 4), (10, 4), (11, 4), (12, 4), (14, 4), (15, 4), (17, 4), (19, 4),
             (0, 5), (7, 5), (12, 5), (19, 5),
             (0, 6), (2, 6), (4, 6), (5, 6), (7, 6), (8, 6), (11, 6), (12, 6), (14, 6), (15, 6), (17, 6), (19, 6),
             (0, 7), (2, 7), (17, 7), (19, 7),
             (0, 8), (2, 8), (3, 8), (5, 8), (7, 8), (8, 8), (9, 8), (10, 8), (11, 8), (12, 8), (14, 8), (16, 8), (17, 8), (19, 8),
             (0, 9), (5, 9), (14, 9), (19, 9),
             (0, 10), (1, 10), (2, 10), (3, 10), (4, 10), (5, 10), (6, 10), (7, 10), (8, 10), (9, 10), (10, 10), (11, 10), (12, 10), (13, 10), (14, 10), (15, 10), (16, 10), (17, 10), (18, 10), (19, 10)]

game = Game(pacmanPos, pinkyPos, blinkyPos, dotPoses, wallPoses)
game.drawBoard()
while True:
    if game.pacman.position == game.pinky.position or game.pacman.position == game.blinky.position:
        sleep(0.2)
        os.system('cls')
        game.gameOver()
        exit()
    elif len(game.dotPoses) == 0:
        sleep(0.2)
        os.system('cls')
        game.youWon()
        exit()
    else:
        if game.turn == "pacman":
            if len(game.pacman.nextPoses) == 0:
                game.pacman.updateNextPoses(7)
            game.pacman.updatePosition()
            game.pinky.updatePacmanPos(game.pacman.position)
            game.blinky.updatePacmanPos(game.pacman.position)
            game.pacman.updateDotPoses()
            game.pacman.updateCountOfMove()
            game.pacman.updateScore()
            game.updateDotPoses()
            sleep(0.2)
            os.system('cls')
            game.drawBoard()
            game.updateTurn("pinky")
            continue
        if game.turn == "pinky":
            game.pinky.updatePosition()
            game.pacman.updatePinkyPos(game.pinky.position)
            game.blinky.updateFriendPos(game.pinky.position)
            sleep(0.2)
            os.system('cls')
            game.drawBoard()
            game.updateTurn("blinky")
            continue
        if game.turn == "blinky":
            game.blinky.updatePosition()
            game.pacman.updateBlinkyPos(game.blinky.position)
            game.pinky.updateFriendPos(game.blinky.position)
            sleep(0.2)
            os.system('cls')
            game.drawBoard()
            game.updateTurn("pacman")