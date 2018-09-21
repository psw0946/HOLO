import urllib.request as dw

print('hi')
print('한글')

imgUrl = "http://post.phinf.naver.net/MjAxNzA4MzBfMjI2/MDAxNTA0MDY4NTg3NjQ1.BFV5_WOXYE7ApU120zcjzIlZAK1dpxTfEIOSVwmCO-0g.3rKiPj6tB9SNMGseO86dPHGAY2cpvVLecYeuTvhYaDYg.JPEG/IjjiXPKuOOHnJvf4bW3qnq4My5L0.jpg"
htmlURL = "http://google.com"

savePath1 = "C:/Users/PSW/Desktop/HOLO/WebCrawler/test1.jpg"
savePath2 = "C:/Users/PSW/Desktop/HOLO/WebCrawler/index.html"

dw.urlretrieve(imgUrl, savePath1) # imgUrl의 이미지를 savePath에 다운로드
dw.urlretrieve(htmlURL, savePath2)

print("다운로드 완료!")

