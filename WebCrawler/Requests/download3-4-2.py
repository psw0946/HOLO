import requests
import urllib.parse as rep
import urllib.request as req
from bs4 import BeautifulSoup
import os

# 로그인 유저 정보
LOGIN_INFO = {
    'log': 'outsider7224',
    'pwd': 'dmsrl8482',
    'user-submit': rep.quote_plus('로그인'),
    'user-cookie': 1
}

with requests.Session() as s:
    login_req = s.post('https://www.inflearn.com/wp-login.php?redirect_to=https%3A%2F%2Fwww.inflearn.com%2F', data=LOGIN_INFO)
    # HTML 소스 확인
    # print('login_req', login_req.text)
    # Header 확인
    # print('headers', login_req.headers)
    if login_req.status_code == 200 and login_req.ok:
        post_one = s.get("https://www.inflearn.com/members/outsider7224/")
        post_one.raise_for_status()
        soup = BeautifulSoup(post_one.text, 'html.parser')
        # print(soup.prettify())
        badges = soup.select("div.badges > ul > li > a > img")
        for i, z in enumerate(badges, 1):
            # print(z)
            fullFileName = os.path.join("c:/", str(i) + ".jpg")
            req.urlretrieve(z['src'], fullFileName)
