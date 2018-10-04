import simplejson as json
# from tinydb.storages import MemoryStorage
from tinydb import TinyDB, Query

# 파일 DB 생성
db = TinyDB('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/databases/database.db', default_table='users')

# 메모리 DB 생성
# db = TinyDB(storage=MemoryStorage, default_table='users') 파일을 새로 만들지 않고 메모리에 저장

# 테이블 선택
users = db.table("users")
todos = db.table("todos")

# users 테이블 출력
for item in users:
    # print(item['username'], ':', item['phone'])
    pass

# todos 테이블 출력
for item in todos:
    # print(item['title'], ':', item['completed'])
    pass

# 연결 관계 출력(조건문)
for item in users:
    # print('[', item['username'], ']')
    pass
    for todo in todos:
        if todo['userId'] == item['id']:
            # print(todo['title'])
            pass

# 쿼리 객체 사용 조회
# SQL = Query() 구분 안하고 하나로 해도 되긴 함
Users = Query()
Todos = Query()

# Row 수정
users.update({'username': 'kim'}, Users.id == 3) # id가 3번인 것의 username을 kim으로

user_3 = users.search(Users.id == 3) # >, <, >=, <=
print(user_3)

# Row 삭제
users.remove(Users.id == 3)
print(users.search(Users.id == 3))
