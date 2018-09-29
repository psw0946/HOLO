import requests, json

s = requests.Session()

r = s.get("http://httpbin.org/stream/20", stream=True)
# print(r.text) json 형태가 아님. 단순히 20개를 줄바꿈한 형태
# print(r.encoding)
if r.encoding is None:
    r.encoding = 'utf-8'

for line in r.iter_lines(decode_unicode=True):
    # print(line)
    b = json.loads(line)
    # print(type(b)) --> dict
    for e in b.keys():
        print("key:", e, "values:", b[e])

s.close()