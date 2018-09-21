import urllib.request as dw

print('hi')
print('한글')

imgUrl = "http://post.phinf.naver.net/MjAxNzA4MzBfMjI2/MDAxNTA0MDY4NTg3NjQ1.BFV5_WOXYE7ApU120zcjzIlZAK1dpxTfEIOSVwmCO-0g.3rKiPj6tB9SNMGseO86dPHGAY2cpvVLecYeuTvhYaDYg.JPEG/IjjiXPKuOOHnJvf4bW3qnq4My5L0.jpg"
htmlURL = "http://google.com"

savePath1 = "C:/Users/PSW/Desktop/HOLO/WebCrawler/test1.jpg"
savePath2 = "C:/Users/PSW/Desktop/HOLO/WebCrawler/index.html"

f = dw.urlopen(imgUrl).read()
f2 = dw.urlopen(htmlURL).read()

saveFile1 = open(savePath1, 'wb') # w : write, r : read, a : add(파일의 끝부분부터 추가)
saveFile1.write(f)
saveFile1.close()

with open(savePath2, 'wb') as saveFile2:
    saveFile2.write(f2)
# with 문은 벗어날 때 close를 자동으로 해줌

print("다운로드 완료!")

# urlretrieve VS urlopen
# urlretrieve : 파싱이 필요 없이 그냥 다운받아버릴 때
# urlopen : 파싱을 한 후에 가공하여 다시 써줄 때
