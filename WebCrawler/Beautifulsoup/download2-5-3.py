from bs4 import BeautifulSoup

html = """
<html><body>
    <ul>
        <li><a href="http://www.naver.com">naver</a></li>
        <li><a href="http://www.daum.net">daum</a></li>
        <li><a href="http://www.daum.com">daum</a></li>
        <li><a href="https://www.google.com">google</a></li>
        <li><a href="https://www.tistory.com">tistory</a></li>
    </ul>
</body></html>
"""

soup = BeautifulSoup(html, 'html.parser')

links = soup.find_all("a")
#print('links', type(links))

a = soup.find_all("a", string="daum") # daum 글자 들어간 것만 가져옴
#print('a', a)

b = soup.find('a') # 최상위 한 개만 가져옴
#print('b', b)

b = soup.find_all("a", limit=1) # limit = 0 이면 다 가져옴
#print('b', b)

c = soup.find_all(string=["naver", "google"]) # 해당 글자가 들어가면 가져옴(글자만) (원래는 정규식같은거로 씀)
print('c', type(c))

for a in links:
    #print('a', type(a), a)
    href = a.attrs['href']
    txt = a.string
    #print('txt >>', txt, 'href >>', href)
