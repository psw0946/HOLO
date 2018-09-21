import pytube
import os
import subprocess # 터미널 실행 가능

yt = pytube.YouTube("https://www.youtube.com/watch?v=ePkDDWSnr2w") # 다운 받을 동영상 URL 지정
videos = yt.streams.all()

#print('videos', videos) # 다운받을 수 있는 리스트를 출력

for i in range(len(videos)):
    print(i, ' , ', videos[i])

down_dir = "C:/Users/PSW/Desktop/HOLO/WebCrawler/Youtube"

cNum = int(input("다운 받을 화질은?(0 ~ %d 입력)" % (len(videos) - 1)))

videos[cNum].download(down_dir)

newFileName = input("변환 할 mp3 파일명은?")
oriFileName = videos[cNum].default_filename

subprocess.call(['ffmpeg', '-i',
    os.path.join(down_dir, oriFileName),
    os.path.join(down_dir, newFileName),
]) # 위치는 현재 파일 디렉토리 기준

print("동영상 다운로드 및 mp3 변환 완료!")
