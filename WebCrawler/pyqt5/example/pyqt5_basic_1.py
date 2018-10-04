import sys
from PyQt5.QtWidgets import *

app = QApplication(sys.argv)
# print(sys.argv) 현재 실행 파일 경로
label = QLabel("PyQt First Test!")
label.show()

print("Before Loop")
app.exec_()
print("After Loop")
