import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5 import uic # ui 파일을 컴파일해서 가져오는...
from pyqt5_basic_ui import Ui_MainWindow
# pyuic5 -x pyqt5_basic_3.ui -o pyqt5_basic_ui.py (cmd)

# form_class = uic.loadUiType('C:/Users/PSW/Desktop/HOLO/WebCrawler/pyqt5/example/pyqt5_basic_3.ui')[0] ui파일을 python 파일로 변경해서 쓰는 게 더 효율적임

class TestForm(QMainWindow, Ui_MainWindow): # TestForm(QMainWindow, form_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TestForm()
    window.show()

    app.exec_()
