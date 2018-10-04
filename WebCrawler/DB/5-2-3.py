import simplejson as json
from tinydb import TinyDB, Query, where

# 파일 DB 생성
db = TinyDB('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/databases/database.db', default_table='users')

# 테이블 선택
users = db.table("users")
todos = db.table("todos")

Users = Query()
Todos = Query()

# Users 여러 가지 조회 방법
print(users.search(Users.id == 7))
print(users.search(Users["id"] == 7))
print(users.search(where('id') == 7))
print(users.search(Query()['id'] == 7))
print(users.search(where('address')['zipcode'] == '90566-7771'))
print(users.search(where('address').zipcode == '90566-7771'))

# 고급 쿼리
print(users.search(Users.email.exists())) # 10개를 다 갖고 옴
print(users.search(Users['email'].exists())) # 10개를 다 갖고 옴
print(users.search(Users.aaa.exists()))

# NOT
print('not', users.search(~(Users.username == 'Antonette')))

# OR
print('or', users.search((Users.username == 'Antonette') | (Users.username == 'Kamren')))

# AND
print('and', users.search((Users.username == 'Antonette') & (Users.id == 2)))

# 기타 함수
print('len', len(users))
print('len', len(todos))
print('contains', users.contains(Users.username == 'Kamren'))
print('count', users.count(Users.username == 'Kamren'))
