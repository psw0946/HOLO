import urllib.request as req
from urllib.parse import urlparse

url = "http://www.encar.com"

mem = req.urlopen(url)

#print(type(mem))
#print(type({})) # dict
#print(type([])) # list
#print(type(())) # tuple

#print("geturl", mem.geturl())
#print("status", mem.status)
#print("headers", mem.getheaders())

#print("info", mem.info())
#print("code", mem.getcode()) # status랑 같은듯
#print("read", mem.read(50).decode("utf-8")) # 괄호 안에 숫자 없으면 다 읽어옴 # euc-kr ...
print(urlparse("http://www.encar.com?test=test"))
