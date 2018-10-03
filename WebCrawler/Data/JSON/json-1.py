import simplejson as json
# import json

# Dict(Json) 선언
data = {}
data['people'] = []
data['people'].append({
    'name': 'Kim',
    'website': 'naver.com',
    'from': 'Seoul'
})
data['people'].append({
    'name': 'Park',
    'website': 'google.com',
    'from': 'Busan'
})
data['people'].append({
    'name': 'Lee',
    'website': 'daum.net',
    'from': 'Incheon'
})

# print(data)

# Dict(Json) -> Str
e = json.dumps(data, indent=4) # indent는 들여쓰기 용도, indent가 없으면 쭉 이어서 써짐
# print(type(e))
# print(e)

# Str -> Dict(Json)
d = json.loads(e)
# print(type(d))
# print(d)

with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/member.json', 'w') as outfile:
    outfile.write(e)

with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/member.json', 'r') as infile:
    r = json.loads(infile.read())
    print("====")
    # print(type(r))
    # print(r)
    for p in r['people']:
        print('Name: ' + p['name'])
        print('website: ' + p['website'])
        print('From: ' + p['from'])
        print('')
