from PyQt5.QtCore import QObject, pyqtSlot, pyqtSignal
from PyQt5.QtMultimedia import QSound


class IntroWorker(QObject): # 별도의 스레드를 생성할 때 QObject를 상속
    startMsg = pyqtSignal(str, str)
    @pyqtSlot()
    def playBgm(self):
        self.intro = QSound('C:/Users/PSW/Desktop/HOLO/WebCrawler/pyqt5/resource/intro.wav')
        self.intro.play()
        self.startMsg.emit('Anonymous', self.intro.fileName()) # 시그널 보내
