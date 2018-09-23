from bs4 import BeautifulSoup
import urllib.request as req
import urllib.parse as rep
import os
import errno

base = "https://www.inflearn.com/"
quote = rep.quote_plus("추천-강좌")
url = base + quote

res = req.urlopen(url)
savePath = "C:/Users/PSW/Desktop/HOLO/WebCrawler/Beautifulsoup/imagedown"

try:
    if not (os.path.isdir(savePath)):
        os.makedirs(os.path.join(savePath))
except OSError as e:
    if e.errno != errno.EEXIST:
        print("폴더 만들기 실패")
        raise

soup = BeautifulSoup(res, "html.parser")

img_list1 = soup.select("ul.slides")[1]
img_list2 = soup.select("ul.slides")[2]

i = 1
for e in img_list1:
    with open(os.path.join(savePath, "text_" + str(i) + ".txt"), "wt") as f:
        f.write(e.select_one("h4.block_title > a").string)
    fullFileName = os.path.join(savePath, str(i) + ".png")
    req.urlretrieve(e.select_one("div.block_media > a > img")['src'], fullFileName)
    i += 1
for e in img_list2:
    with open(os.path.join(savePath, "text_" + str(i) + ".txt"), "wt") as f:
        f.write(e.select_one("h4.block_title > a").string)
    fullFileName = os.path.join(savePath, str(i) + ".png")
    req.urlretrieve(e.select_one("div.block_media > a > img")['src'], fullFileName)
    i += 1

print("다운로드 완료")

