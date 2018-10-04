import sqlite3
import simplejson as json
import datetime

# DB 생성
conn = sqlite3.connect('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/databases/sqlite1.db') # isolation_level=None: AutoCommit(하나의 쿼리 실행할 때마다 commit 자동 실행)
# DB 생성(메모리DB)
# conn = sqlite3.connect(":memory:")

# 날짜 생성
now = datetime.datetime.now()
print('now', now)

nowDatetime = now.strftime('%Y-%m-%d %H:%M:%S')
print('nowDatetime', nowDatetime)

# sqlite3 버전 확인
print('sqlite3.version', sqlite3.version)
print('sqlite3.sqlite_version', sqlite3.sqlite_version)

# Cursor 연결
c = conn.cursor()
print(type(c))

# 테이블 생성(SQLite3 Datatype : TEXT, NUMERIC, INTEGER, REAL, BLOB)
c.execute("CREATE TABLE IF NOT EXISTS users(id integer PRIMARY KEY, username text, email text, phone text, website text, regdate text)") # AUTOINCREMENT를 id에 적용 가능

# 데이터 삽입
# c.execute("INSERT INTO users VALUES(1, 'kim', 'kim@naver.com', '010-0000-0000', 'kim.co.kr', ?)", (nowDatetime, )) # 튜플이기 때문에 , 붙임

userList = (
    (2, 'kim', 'kim@naver.com', '010-0000-0000', 'kim.co.kr', nowDatetime),
    (3, 'kim', 'kim@naver.com', '010-0000-0000', 'kim.co.kr', nowDatetime),
    (4, 'kim', 'kim@naver.com', '010-0000-0000', 'kim.co.kr', nowDatetime)
)
# c.executemany("INSERT INTO users(id, username, email, phone, website, regdate) VALUES (?,?,?,?,?,?)", userList)

with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/data/users.json', 'r') as infile:
    r = json.load(infile)
    userData = []
    for user in r:
        t = (user['id'], user['username'], user['email'], user['phone'], user['website'], nowDatetime)
        # print('t', t)
        userData.append(t)
        # c.execute("insert ~~", t) 하나씩 넣어줘도 됨
    # print('userData', userData)
    # print('userData', tuple(userData))
    # c.executemany("INSERT INTO users(id, username, email, phone, website, regdate) VALUES (?,?,?,?,?,?)", userData) # 알아서 튜플로 형변환 해줌
    c.executemany("INSERT INTO users(id, username, email, phone, website, regdate) VALUES (?,?,?,?,?,?)", tuple(userData))

# print('users db delete', conn.execute("delete from users").rowcount, "rows") # rowcount로 삭제한 행 수 반환
conn.commit()

conn.close()
