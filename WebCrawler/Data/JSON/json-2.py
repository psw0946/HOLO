import simplejson as json
# import json

# Dict(Json) 선언
data = {}
data['people'] = []
data['people'].append({
    'name': 'Kim',
    'website': 'naver.com',
    'from': 'Seoul',
    'grade': [95, 77, 89, 91]
})
data['people'].append({
    'name': 'Park',
    'website': 'google.com',
    'from': 'Busan',
    'grade': [85, 67, 100, 93]
})
data['people'].append({
    'name': 'Lee',
    'website': 'daum.net',
    'from': 'Incheon',
    'grade': [98, 79, 99, 92]
})

# json 파일쓰기(dump)
with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/member.json', 'w') as outfile:
    json.dump(data, outfile)

with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/member.json', 'r') as infile:
    r = json.load(infile)
    # print(type(r))
    # print(r)
    print('=======================')
    for p in r['people']:
        print('Name: ' + p['name'])
        print('website: ' + p['website'])
        print('From: ' + p['from'])
        grade = ''
        for g in p['grade']:
            grade = grade + ' ' + str(g)
        print('Grade:', grade.lstrip()) # 왼쪽 공백 제거
        print('')

