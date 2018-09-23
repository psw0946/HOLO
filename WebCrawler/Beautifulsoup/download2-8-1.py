from bs4 import BeautifulSoup
import urllib.request as req
import urllib.parse as rep
import os
import errno

# 네이버에서 헤더 정보가 없는 크롤링 및 스크랩핑은 403 forbidden (접근 거부) 처리하고 있어서 밑에 헤더정보 추가
opener = req.build_opener()
opener.addheaders = [('User-agent', 'Mozilla/5.0')]
req.install_opener(opener)

base = "https://search.naver.com/search.naver?where=image&sm=tab_jum&query="
quote = rep.quote_plus("멍뭉이")
url = base + quote

res = req.urlopen(url)
savePath = "C:/Users/PSW/Desktop/HOLO/WebCrawler/Beautifulsoup/imagedown"

try:
    if not (os.path.isdir(savePath)): # 그러한 디렉토리가 있는지 확인
        os.makedirs(os.path.join(savePath)) # 없으면 디렉토리를 만들어낸다
except OSError as e:
    if e.errno != errno.EEXIST:
        print("폴더 만들기 실패!")
        raise

soup = BeautifulSoup(res, "html.parser")

img_list = soup.select("div.img_area > a.thumb._thumb > img") # 크롬 개발자 도구의 Copy selector 를 이용하면 쉽게 보여줌

for i, img_list in enumerate(img_list, 1):
    #print(img_list['src']) base64 형식으로 변환된 소스... 이거로는 다운받을 수 없다.
    #print(img_list['data-source'])
    fullFileName = os.path.join(savePath, str(i) + ".jpg")
    #print(fullFileName)
    req.urlretrieve(img_list['data-source'], fullFileName)

print("다운로드 완료")
