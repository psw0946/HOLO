import requests
from bs4 import BeautifulSoup
from fake_useragent import UserAgent

#요청 URL
URL = 'https://www.wishket.com/accounts/login/'

# Fake User-Agent 생성
ua = UserAgent()
# print(ua.ie)
# print(ua.chrome)
# print(ua.random)

with requests.Session() as s:
    # URL 연결
    s.get(URL)
    # Login 정보 Payload
    LOGIN_INFO = {
        'identification': 'outsider7224',
        'password': '12134',
        'csrfmiddlewaretoken': s.cookies['csrftoken']
    }
    # 요청
    response = s.post(URL, data=LOGIN_INFO, headers={'User-Agent': str(ua.chrome), 'Referer': 'https://www.wishket.com/accounts/login/'})
    # HTML 결과 확인
    # print('response', response.text)
    if response.status_code == 200 and response.ok:
        soup = BeautifulSoup(response.text, 'html.parser')
        projectList = soup.select("table.table-responsive > tbody > tr")
        for i in projectList:
            print(i.find('th').string, i.find('td').text)
# Chrome 로그인 과정에서 Preserve Log 하고 그 과정을 잘 지켜보고 분석.
