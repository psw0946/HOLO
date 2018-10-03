import datetime
import urllib.request as req
from bs4 import BeautifulSoup
import os.path

url = "http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4373025000"
savename = 'C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/forecast_assignment.xml'

if not os.path.exists(savename):
    req.urlretrieve(url, savename)

xml = open(savename, 'r', encoding='utf-8').read()
soup = BeautifulSoup(xml, 'html.parser')

info = {}
now = datetime.datetime.now()
for data in soup.find_all("data"):
    day = int(data.find('day').string)
    date = (now + datetime.timedelta(days=day)).strftime('%Y-%m-%d')
    if not (date in info):
        info[date] = []
    hour = data.find('hour').string
    temp = data.find('temp').string
    weather = data.find('wfkor').string
    information = {'h': hour, 't': temp, 'w': weather}
    info[date].append(information)

with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/forecast_assignment.txt', 'wt') as f:
    for date in sorted(info.keys()):
        f.write(date + '\n')
        for information in info[date]:
            f.write('\t' + '시간: ' + information['h'] + '\n')
            f.write('\t' + '날씨: ' + information['w'] + '\n')
            f.write('\t' + '온도: ' + information['t'] + '\n')
