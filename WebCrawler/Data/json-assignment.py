import simplejson as json
import requests

url = 'https://jsonplaceholder.typicode.com/posts'
res = requests.get(url)
json_res = res.json()
data = {}
data['parsing'] = []
for post in json_res:
    if 'title' in post:
        item = {}
        item['id'] = post['id']
        item['title'] = post['title']
        item['userId'] = post['userId']
        data['parsing'].append(item)

# json 파일쓰기(dump)
with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/assignment.json', 'w') as outfile:
    json.dump(data, outfile)

with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/assignment.json', 'r') as infile:
    r = json.load(infile)
    for post in r['parsing']:
        print(post['title'])
