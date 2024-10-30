import PyQt5
from PyQt5 import QtWidgets
from PyQt5 import QtCore
from PyQt5 import QtGui
from PyQt5 import uic

import sys
import random


class ms(QtWidgets.QMainWindow):
    def __init__(self):
        super(ms, self).__init__()

        uic.loadUi("ms_main.ui", self)

        self.l = 15

        self.msb = {n+1:QtWidgets.QPushButton(self) for n in range(self.l**2)}

        for var1 in range(self.l):
            for var2 in range(self.l):
                self.msb[(var1*self.l)+var2+1].setGeometry(20+var1*(360//self.l),21+var2*(360//self.l),(360//self.l),(360//self.l))
                self.msb[(var1*self.l)+var2+1].setStyleSheet("background-color : cyan; color : cyan")
                self.msb[(var1*self.l)+var2+1].setFont(QtGui.QFont("Verdana",(180//self.l)))
                self.msb[(var1*self.l)+var2+1].clicked.connect(self.bomb_or_not)
                self.msb[(var1*self.l)+var2+1].mouseDoubleClickEvent.connect(self.mine_setup)


        self.board_make()
        self.show()

    
    def board_make(self):
        self.board = [[0]*self.l for _ in range(self.l)]
        for _ in range(int(self.l**1.3)):
            row,col = random.randint(0,self.l-1),random.randint(0,self.l-1)
            while self.board[row][col] == "X":
                row,col = random.randint(0,self.l-1),random.randint(0,self.l-1)
            self.board[row][col] = "X"

            for r in range(row-1,row+2):
                for c in range(col-1,col+2):
                    if (0<=r<self.l) and (0<=c<self.l) and (self.board[r][c] != "X"):
                        self.board[r][c] += 1

            for i in range(self.l):
                for j in range(self.l):
                    self.msb[(i*self.l)+j+1].setText(f"{self.board[i][j]}")

        return self.board
    

    def bomb_or_not(self):
        self.button = self.sender()

        if (self.button.text() == "X"):
            for i in range(1,(self.l**2)+1):
                if (self.msb[i].text() == "X"):
                    self.msb[i].setStyleSheet("background-color : white; color : black")
                    self.msb[i].blockSignals(True)

        elif (self.button.text() == "0"):
            for i in range(1,(self.l**2)+1):
                if (self.msb[i].text() == "0"):
                    self.msb[i].setText("")
                    self.msb[i].setStyleSheet("background-color : white; color : black")

        else:
            self.button.setStyleSheet("background-color : white; color : black")


    def mine_setup(self):
        self.button = self.sender()
        self.button.
        self.msb[1].setIcon("")

        
app = QtWidgets.QApplication(sys.argv)
window = ms()
app.exec_()