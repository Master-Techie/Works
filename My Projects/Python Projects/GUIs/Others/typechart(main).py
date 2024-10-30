from PyQt5 import QtWidgets, QtGui, QtCore, uic
import sys


class Class(QtWidgets.QMainWindow):
    def __init__(self):
        super(Class, self).__init__()
        uic.loadUi("typechart(main).ui", self)

        self.info = {n+1:QtWidgets.QPushButton(self) for n in range(360)}
        self.showboard()

        for i in range(1,19):
            self.info[i].setGeometry(40+(20*i),0,20,120)
            self.info[i].setText(self.list1[i-1])
            self.info[i].setStyleSheet("QPushButton { text-align: top; }")

            self.info[19*i].setGeometry(0,100+(20*i),60,20)
            self.info[19*i].setText(self.lst1[i-1])
            self.info[19*i].setStyleSheet("QPushButton { text-align: left; }")

            for j in range(1,19):
                self.info[(19*i)+j].setGeometry(40+(20*i),100+(20*j),20,20)

                if self.list20[i-1][j] == "-":
                    self.info[(19*i)+j].setStyleSheet("QPushButton { background-color: green}")

                if self.list20[i-1][j] == "+":
                    self.info[(19*i)+j].setStyleSheet("QPushButton { background-color: red}")

                if self.list20[i-1][j] == "*":
                    self.info[(19*i)+j].setStyleSheet("QPushButton { background-color: black}")

        
        self.show()


    def showboard(self):

        self.list1=["Grass","Fire","Water","Normal","Bug","Poison","Flying","Electric","Ground","Rock","Ice","Steel","Fight","Dark","Ghost","Psychic","Dragon","Fairy"]

        self.list2=[self.list1[0]]+["-","-","+","","-","-","-","","+","+","","-","","","","","-",""]
        self.list3=[self.list1[1]]+["+","-","-","","+","","","","","-","+","+","","","","","-",""]
        self.list4=[self.list1[2]]+["-","+","-","","","","","","+","+","","","","","","","-",""]
        self.list5=[self.list1[3]]+["","","","","","","","","","-","","-","","","*","","",""]
        self.list6=[self.list1[4]]+["+","-","","","","-","-","","","","","-","-","+","-","+","","-"]
        self.list7=[self.list1[5]]+["","","","","","","","","","","","","","","","","",""]
        self.list8=[self.list1[6]]+["","","","","","","","","","","","","","","","","",""]
        self.list9=[self.list1[7]]+["","","","","","","","","","","","","","","","","",""]
        self.list10=[self.list1[8]]+["","","","","","","","","","","","","","","","","",""]
        self.list11=[self.list1[9]]+["","","","","","","","","","","","","","","","","",""]
        self.list12=[self.list1[10]]+["","","","","","","","","","","","","","","","","",""]
        self.list13=[self.list1[11]]+["","","","","","","","","","","","","","","","","",""]
        self.list14=[self.list1[12]]+["","","","","","","","","","","","","","","","","",""]
        self.list15=[self.list1[13]]+["","","","","","","","","","","","","","","","","",""]
        self.list16=[self.list1[14]]+["","","","","","","","","","","","","","","","","",""]
        self.list17=[self.list1[15]]+["","","","","","","","","","","","","","","","","",""]
        self.list18=[self.list1[16]]+["","","","","","","","","","","","","","","","","",""]
        self.list19=[self.list1[17]]+["","","","","","","","","","","","","","","","","",""]

        for i in range(len(self.list1)):
            a="\n".join(self.list1[i])
            self.list1[i]=a
            
        self.list20=[self.list2,self.list3,self.list4,self.list5,self.list6,self.list7,self.list8,self.list9,self.list10,self.list11,self.list12,self.list13,self.list14,self.list15,self.list16,self.list17,self.list18,self.list19]

        print(self.list20,"\n\n")

        self.lst1=["Grass","Fire","Water","Normal","Bug","Poison","Flying","Electric","Ground","Rock","Ice","Steel","Fight","Dark","Ghost","Psychic","Dragon","Fairy"]

        # lst2=[lst1[0]]+["" for i in range(18)]
        # lst3=[lst1[1]]+["" for i in range(18)]
        # lst4=[lst1[2]]+["" for i in range(18)]
        # lst5=[lst1[3]]+["" for i in range(18)]
        # lst6=[lst1[4]]+["" for i in range(18)]
        # lst7=[lst1[5]]+["" for i in range(18)]
        # lst8=[lst1[6]]+["" for i in range(18)]
        # lst9=[lst1[7]]+["" for i in range(18)]
        # lst10=[lst1[8]]+["" for i in range(18)]
        # lst11=[lst1[9]]+["" for i in range(18)]
        # lst12=[lst1[10]]+["" for i in range(18)]
        # lst13=[lst1[11]]+["" for i in range(18)]
        # lst14=[lst1[12]]+["" for i in range(18)]
        # lst15=[lst1[13]]+["" for i in range(18)]
        # lst16=[lst1[14]]+["" for i in range(18)]
        # lst17=[lst1[15]]+["" for i in range(18)]
        # lst18=[lst1[16]]+["" for i in range(18)]
        # lst19=[lst1[17]]+["" for i in range(18)]

        # for i in range(len(lst1)):
        #     a="\n".join(lst1[i])
        #     lst1[i]=a

        # lst20=[lst2,lst3,lst4,lst5,lst6,lst7,lst8,lst9,lst10,lst11,lst12,lst13,lst14,lst15,lst16,lst17,lst18,lst19]

        # print(lst20)



app = QtWidgets.QApplication(sys.argv)
window = Class()
app.exec_()