import urllib.request as req
from urllib.parse import urlencode

API = "http://www.mois.go.kr/gpms/view/jsp/rss/rss.jsp"

values = {
    'ctxCd': '1001'
}
print("before", values)
params = urlencode(values)
print("after", params)

url = API + "?" + params
print("요청 url", url)

reqData = req.urlopen(url).read().decode('utf-8')
print("출력", reqData)
