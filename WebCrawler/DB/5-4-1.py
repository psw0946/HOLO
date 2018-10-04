import pymysql
import simplejson as json
import datetime

# MYSQL Connection
conn = pymysql.connect(host='localhost', user='python', password='ZXcasc', db='python_app1', charset='utf8')

# pyMysql 버전 확인
print('pymysql.version', pymysql.__version__)

# 데이터베이스 선택
# conn.select_db('python_app1') 중간에 table change 할 때 이거 사용

# Cursor 연결
c = conn.cursor()
print(type(c))

# 데이터베이스 생성
# c.execute('create database python_app2') # DDL, DML, DCL

# 커서 반환
# c.close()

# 접속 해제
# conn.close()

# 트랜잭션 시작 선언
# conn.begin()

# 커밋
# conn.commit()

# 롤백
# conn.rollback()

# 날짜 생성
now = datetime.datetime.now()
nowDatetime = now.strftime('%Y-%m-%d %H:%M:%S')

c.execute('CREATE TABLE IF NOT EXISTS users (id bigint(20) NOT NULL, username VARCHAR(20), email VARCHAR(30), phone VARCHAR(30), website VARCHAR(30), regdate VARCHAR(20) NOT NULL, PRIMARY KEY(id))')
# AUTO_INCREMENT, DEFAULT(내용 없이 삽입될 때 이 값으로 저장) 옵션 존재
conn.commit()

try:
    with conn.cursor() as c:
        # JSON to Mysql
        with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/data/users.json', 'r') as infile:
            r = json.load(infile)
            userData = []
            for user in r:
                t = (user['id'], user['username'], user['email'], user['phone'], user['website'], nowDatetime)
                userData.append(t)
            c.executemany('INSERT INTO users (id, username, email, phone, website, regdate) VALUES (%s, %s, %s, %s, %s, %s)', userData)
        conn.commit()
finally:
    conn.close()
