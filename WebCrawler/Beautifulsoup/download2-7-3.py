from bs4 import BeautifulSoup
import urllib.request as req
import urllib.parse as rep

base = "https://www.inflearn.com/"
quote = rep.quote_plus("추천-강좌") # 한글을 유니코드로 바꿔주는 작업 필수

url = base + quote

res = req.urlopen(url).read()
soup = BeautifulSoup(res, "html.parser")

recommend = soup.select("ul.slides")[0]
for i, e in enumerate(recommend, 1):
    print(i, e.select_one("h4.block_title > a").string)
