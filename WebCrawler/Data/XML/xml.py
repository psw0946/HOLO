import urllib.request as req
from bs4 import BeautifulSoup
import os.path

# 다운로드 url
url = "http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=108"
savename = 'C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/forecast.xml'

if not os.path.exists(savename):
    req.urlretrieve(url, savename)

# BeautifulSoup 파싱
xml = open(savename, 'r', encoding='utf-8').read()
soup = BeautifulSoup(xml, 'html.parser') # XML도 html.parser

# 지역확인
info = {}
for location in soup.find_all("location"): # XML은 사용자 정의 태그로 이루어져 있기 때문에 find와 find_all로 많이 쓴다
    loc = location.find("city").string
    # print(loc)
    weather = location.find_all("tmn")
    # print(weather)
    if not (loc in info): # key 중복 검사
        info[loc] = []
    for tmn in weather:
        info[loc].append(tmn.string)
# print(info)
# print(info.keys())
# print(sorted(info.keys()))
# print(list(info.keys()))
# print(info.values())

# 각 지역별 날씨 텍스트 쓰기
with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/forecast.txt', 'wt') as f:
    for loc in sorted(info.keys()):
        print("+", loc)
        f.write(str(loc) + '\n')
        for n in info[loc]:
            print("-", n)
            f.write('\t' + str(n) + '\n')

