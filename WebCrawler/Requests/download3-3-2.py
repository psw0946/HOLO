import requests, json

# Rest: POST, PUT: UPDATE, REPLACE (FETCH: UPDATE, MODIFY), GET, DELETE

payload1 = {'key1': 'value1', 'key2': 'value2'} # dict
payload2 = (('key1', 'value1'), ('key2', 'value2')) # tuple
payload3 = {'some': 'nice'}

# r = requests.put("http://httpbin.org/put", data=payload1)
# print(r.text)

# r = requests.put('https://jsonplaceholder.typicode.com/posts/1', data=payload1)
# print(r.text)

r = requests.delete('https://jsonplaceholder.typicode.com/posts/1') # 1번 글 삭제
print(r.text)
