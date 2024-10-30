import PyQt5
from PyQt5 import QtWidgets
from PyQt5 import QtCore
from PyQt5 import QtGui
from PyQt5 import uic

import chess

import sys
import tabulate
import random


class ms(QtWidgets.QMainWindow):
    def __init__(self):
        super(ms, self).__init__()

        uic.loadUi("ms.ui", self)

        self.msb = {n+1:QtWidgets.QPushButton(self) for n in range(81)}

        for var1 in range(9):
            for var2 in range(9):
                self.msb[(var1*9)+var2+1].setGeometry(20+var1*40,160+var2*40,40,40)
                self.msb[(var1*9)+var2+1].setStyleSheet("background-color : cyan; color : cyan")
                self.msb[(var1*9)+var2+1].clicked.connect(self.bomb_or_not)


        self.board_make()
        self.show()

    
    def board_make(self):
        self.board = [[0]*9 for _ in range(9)]
        for _ in range(10):
            row,col = random.randint(0,7),random.randint(0,7)
            while self.board[row][col] == "X":
                row,col = random.randint(0,7),random.randint(0,7)
            self.board[row][col] = "X"

            for r in range(row-1,row+2):
                for c in range(col-1,col+2):
                    if (0<=r<9) and (0<=c<9) and (self.board[r][c] != "X"):
                        self.board[r][c] += 1

            for i in range(9):
                for j in range(9):
                    self.msb[(i*9)+j+1].setText(f"{self.board[i][j]}")

        return self.board
    

    def bomb_or_not(self):
        self.button = self.sender()

        if (self.button.text() == "X"):
            self.label_2.setText("Fail")
            for i in range(1,82):
                self.msb[i].blockSignals(True)

        elif (self.button.text() == "0"):
            for i in range(1,82):
                if (self.msb[i].text() == "0"):
                    self.msb[i].setText("")
                    self.msb[i].setStyleSheet("background-color : white; color : black")

        else:
            self.button.setStyleSheet("background-color : white; color : black")

        
app = QtWidgets.QApplication(sys.argv)
window = ms()
app.exec_()