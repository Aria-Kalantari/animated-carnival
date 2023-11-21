from agents import Pacman
from agents import Ghost

class Game:
    def __init__(self, pacmanPos, pinkyPos, blinkyPos, dotPoses, wallPoses):
        self.pacman = Pacman(pacmanPos, pinkyPos, blinkyPos, dotPoses, wallPoses, 7)
        self.pinky = Ghost(pinkyPos, pacmanPos, blinkyPos, wallPoses)
        self.blinky = Ghost(blinkyPos, pacmanPos, pinkyPos, wallPoses)
        self.dotPoses = dotPoses
        self.wallPoses = wallPoses
        self.turn = "pacman"

    def drawBoard(self):
        for i in range(10, -1, -1):
            for j in range(0, 20):
                if (j, i) == self.pacman.position: 
                    print('P',end="  ") 
                    continue
                elif (j, i) == self.pinky.position: 
                    print('G',end="  ")
                    continue 
                elif (j, i) == self.blinky.position: 
                    print('G',end="  ")
                    continue
                elif (j, i) in self.dotPoses: 
                    print('.',end="  ")
                    continue
                elif (j, i) in self.wallPoses: 
                    print('#',end="  ")
                    continue
                else: 
                    print(' ',end="  ")
                    continue
            print('\n')
        
        print("***********************", "SCORE : ", self.pacman.updateScore(),"***********************")

    def gameOver(self):
        print("   _____          __  __ ______    ______      ________ _____   \n", 
              "  / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \  \n",
              " | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) | \n",
              " | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  /  \n",
              " | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \  \n",
              "  \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\ ")
    
    def youWon(self):
        print(" __     ______  _    _  __          _______ _   _ \n", 
              " \ \   / / __ \| |  | | \ \        / /_   _| \ | |\n",
              "  \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| |\n",
              "   \   /| |  | | |  | |   \ \/  \/ /   | | | . ` |\n",
              "    | | | |__| | |__| |    \  /\  /   _| |_| |\  |\n",
              "    |_|  \____/ \____/      \/  \/   |_____|_| \_|")

    def updateTurn(self, turn):
        self.turn = turn
    
    def updateDotPoses(self):
        if self.pacman.position == self.dotPoses:
            self.dotPoses.remove(self.pacman.position)