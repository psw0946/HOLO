import pytube

yt = pytube.YouTube("https://www.youtube.com/watch?v=ePkDDWSnr2w") # 다운 받을 동영상 URL 지정
videos = yt.streams.all()

#print('videos', videos) # 다운받을 수 있는 리스트를 출력

for i in range(len(videos)):
    print(i, ' , ', videos[i])

down_dir = "C:/Users/PSW/Desktop/HOLO/WebCrawler/Youtube"

videos[0].download(down_dir)

# 개선 방향
# 1. 다운받을 목록 동적으로 만들기
# 2. ffmpeg -i "동영상이름" ~~.mp3 수동으로 하던거 자동으로
