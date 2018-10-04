import sys
from PyQt5.QtWidgets import *
from PyQt5 import QtWidgets, QtCore

class TestForm(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setupUI()

    def setupUI(self):
        self.setWindowTitle("PyQt Test") # 창 제목
        self.setGeometry(800, 400, 500, 500) # (800, 400) 위치에서 width=500, height=300

        label_1 = QLabel('입력테스트', self)
        label_2 = QLabel('출력테스트', self)

        label_1.move(20, 20)
        label_2.move(20, 60)

        self.lineEdit = QLineEdit("", self) # Default 값
        self.planeEdit = QtWidgets.QPlainTextEdit(self)
        # self.planeEdit.setReadOnly(True) 쓰지 못하고 읽기만 할 수 있음

        self.lineEdit.move(110, 20)
        self.planeEdit.setGeometry(QtCore.QRect(20, 90, 361, 231))

        self.lineEdit.textChanged.connect(self.lineEditChanged)
        self.lineEdit.returnPressed.connect(self.lineEditEnter)

        # 상태바 설정
        self.statusBar = QStatusBar(self)
        self.setStatusBar(self.statusBar)

    def lineEditChanged(self):
        self.statusBar.showMessage(self.lineEdit.text())

    def lineEditEnter(self):
        self.planeEdit.appendPlainText(self.lineEdit.text()) # insertPlainText는 줄바꿈을 하지 않음
        self.lineEdit.clear()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TestForm()
    window.show()

    app.exec_()
