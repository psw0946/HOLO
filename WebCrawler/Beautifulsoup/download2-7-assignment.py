from bs4 import BeautifulSoup
import urllib.request as req

url = "https://www.daum.net/"
res = req.urlopen(url).read()
soup = BeautifulSoup(res, "html.parser")

hotissue = soup.select("div.hotissue_builtin ol.list_hotissue.issue_row > li")
if hotissue is None:
    hotissue = soup.select("div.hotissue_builtin.hide ol.list_hotissue.issue_row > li")

for i, e in enumerate(hotissue, 1):
    info = e.select_one(".txt_issue")
    #print(info.find("a")["href"])
    print(i, info.string, info.find("a")["href"])
