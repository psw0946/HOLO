from bs4 import BeautifulSoup

fp = open("food-list.html", encoding="utf-8")
soup = BeautifulSoup(fp, "html.parser")

print("1", soup.select_one("li:nth-of-type(8)").string)
print("2", soup.select_one("#ac-list > li:nth-of-type(4)").string)
print("3", soup.select("#ac-list > li[data-lo='cn']")[0].string) # > 쓰면 직계자식, 안 쓰면 자손 전체 대상
print("4", soup.select("#ac-list > li.alcohol.high")[0].string) # 띄어쓰기도 . 찍어야함

param = {"data-lo": "cn", "class": "alcohol"}
print("5", soup.find("li", param).string) # dictionary도 옵션으로 가능
print("6", soup.find(id="ac-list").find("li", param).string)

for ac in soup.find_all("li"):
    if ac['data-lo'] == 'us':
        print('data-lo == us', ac.string)
