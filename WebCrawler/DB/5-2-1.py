import simplejson as json
# from tinydb.storages import MemoryStorage
from tinydb import TinyDB

# 파일 DB 생성
db = TinyDB('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/databases/database.db', default_table='users')

# 메모리 DB 생성
# db = TinyDB(storage=MemoryStorage, default_table='users') 파일을 새로 만들지 않고 메모리에 저장

# 테이블 선택
users = db.table("users")
todos = db.table("todos")

# 테이블 데이터 삽입
# users.insert({'name': 'kim', 'email': 'test@google.com'})
# todos.insert({'name': 'homework', 'complete': False})

# 테이블 데이터 전체 삽입 1
with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/data/users.json', 'r') as infile:
    r = json.loads(infile.read())
    for u in r:
        users.insert(u)

# 테이블 데이터 전체 삽입 2
with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/data/todos.json', 'r') as infile:
    r = json.loads(infile.read())
    for t in r:
        todos.insert(t)

# 전체 데이터 출력
print(users.all())
print(todos.all())

# 테이블 목록
print(db.tables())

# 전체 데이터 삭제
# users.purge() # db.purge_table('users') 테이블은 납두고 데이터만 사라짐
# todos.purge() # db.purge_table('todos')

# db.purge_tables() # 테이블까지 지워버림.

db.close()
