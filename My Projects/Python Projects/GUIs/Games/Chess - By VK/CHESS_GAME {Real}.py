import PyQt5
from PyQt5 import QtWidgets
from PyQt5 import QtCore
from PyQt5 import QtGui
from PyQt5 import uic

import chess

import sys
import tabulate


class ChessApp(QtWidgets.QMainWindow):
    def __init__(self):
        super(ChessApp, self).__init__()

        uic.loadUi("CHESS.ui", self)

        self.move = ""

        self.board_rows = [8, 7, 6, 5, 4, 3, 2, 1]
        self.board_columns = 'a b c d e f g h'.split(" ")

        font = QtGui.QFont()
        font.setPointSize(1)

        self.win = None
        self.draw = None

        self.Chess_Board = {n: QtWidgets.QPushButton(self) for n in range(64)}

        for i in range(64):
            self.Chess_Board[i].setFont(font)
            self.Chess_Board[i].setObjectName(f"{self.board_columns[i % 8]}{self.board_rows[i // 8]}")
            self.Chess_Board[i].setGeometry(60 + ((i % 8) * 50), 140 + ((i // 8) * 50), 50, 50)
            self.Chess_Board[i].clicked.connect(self.handle_square_click)
            self.set_square_color(i)

        self.lineEdit_2.setDisabled(True)

        self.pushButton_A.clicked.connect(self.play_move)
        self.pushButton_B.clicked.connect(self.resignation)
        self.pushButton_C.clicked.connect(self.draw_game)
        self.pushButton_D.clicked.connect(self.save_game)
        self.pushButton_E.clicked.connect(self.reset_game)

        self.board = chess.Board()

        self.chessboard()
        self.show_board()
        self.show()

    def set_square_color(self, index):
        row = index // 8
        col = index % 8
        if (row + col) % 2 == 0:
            self.Chess_Board[index].setStyleSheet("QPushButton {background-color : white}")
        else:
            self.Chess_Board[index].setStyleSheet("QPushButton {background-color : grey; color: white}")

    def handle_square_click(self):
        button = self.sender()
        selected_square = button.objectName()

        # If a piece is already selected (first part of the move)
        if self.move:
            self.move += selected_square  # Append the destination square
            self.play_move()
        else:
            piece = button.text()
            # For non-pawn pieces, prepend the piece type (e.g., 'N', 'B', etc.)
            if piece and piece.upper() != 'P':  # 'P' is treated as pawn
                self.move += piece.upper()
            self.move += selected_square  # Add the starting square
        self.update_board_styles(selected_square)

    def play_move(self):
        self.textBrowser.setText("")
        try:
            self.board.push_san(self.move)
            self.move = ""  # Reset the move string after a successful move
            self.chessboard()
            self.show_board()
            if self.board.is_game_over():
                self.handle_game_end()
        except Exception as ex:
            self.textBrowser.setText(str(ex))  # Display error message
            self.move = ""  # Reset the move string on failure


    def update_board_styles(self, selected_square):
        for i in range(64):
            if self.Chess_Board[i].objectName() == selected_square:
                self.Chess_Board[i].setStyleSheet("QPushButton {background-color : cyan}")
            else:
                self.set_square_color(i)

    def chessboard(self):
        self.final_list = []
        pieces = self.board.epd().split(" ", 1)[0]
        rows = pieces.split("/")
        for row in rows:
            row_list = []
            for char in row:
                if char.isdigit():
                    row_list.extend("." * int(char))
                else:
                    row_list.append(char)
            self.final_list.append(row_list)

    def show_board(self):
        for x in range(8):
            for y in range(8):
                index = x * 8 + y
                piece = self.final_list[x][y]
                button = self.Chess_Board[index]
                if piece != ".":
                    icon_path = f"{piece.upper()}@.png" if piece.isupper() else f"{piece.lower()}&.png"
                    button.setIcon(QtGui.QIcon(icon_path))
                    button.setIconSize(QtCore.QSize(40, 40))
                else:
                    button.setIcon(QtGui.QIcon())
                    button.setText("")

    def handle_game_end(self):
        result = "Draw" if self.board.is_draw() else "Checkmate"
        self.textBrowser.setText(f"Game Over: {result}")
        self.disable_game_controls()

    def disable_game_controls(self):
        self.pushButton_A.setDisabled(True)
        self.pushButton_B.setDisabled(True)
        self.pushButton_C.setDisabled(True)

    def reset_game(self):
        self.board.reset()
        self.move = ""
        self.lineEdit.setText("")
        self.lineEdit_2.setText("")
        self.lineEdit.setDisabled(False)
        self.lineEdit_2.setDisabled(True)
        self.textBrowser.setText("")
        self.chessboard()
        self.show_board()
        self.enable_game_controls()

    def enable_game_controls(self):
        self.pushButton_A.setDisabled(False)
        self.pushButton_B.setDisabled(False)
        self.pushButton_C.setDisabled(False)

    def draw_game(self):
        self.textBrowser.setText("It's a draw.")
        self.handle_game_end()

    def resignation(self):
        winner = "White" if self.lineEdit_2.isEnabled() else "Black"
        self.textBrowser.setText(f"{winner} wins by resignation!")
        self.handle_game_end()

    def save_game(self):
        chess_table = tabulate.tabulate(self.final_list, tablefmt="grid", stralign="left")
        with open("chess_save_list.txt", "a") as writer:
            writer.write(chess_table)


app = QtWidgets.QApplication(sys.argv)
window = ChessApp()
app.exec_()
