import urllib.request as dw

savePath1 = "C:/Users/PSW/Desktop/HOLO/WebCrawler/assignment_banner1.jpg"
savePath2 = "C:/Users/PSW/Desktop/HOLO/WebCrawler/assignment_movie1.mp4"

dw.urlretrieve("https://ssl.pstatic.net/tveta/libs/1208/1208268/3ad17387502370af9ed9_20180920152434600.jpg", savePath1)
dw.urlretrieve("https://tvetamovie.pstatic.net/libs/1203/1203736/c5193a16a063d0ebc3c9_20180829191846567.mp4-pBASE-v0-f63152-20180829192044359_1.mp4", savePath2)

print('다운로드 완료')
