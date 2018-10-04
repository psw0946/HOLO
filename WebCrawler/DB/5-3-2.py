import sqlite3

# DB 생성
conn = sqlite3.connect('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/databases/sqlite1.db')

# 커서 바인딩
c = conn.cursor()

# 데이터 조회(전체)
c.execute("SELECT * FROM users") # 커서가 첫번째거 가리킴

# 1개 row 선택
# print(c.fetchone()) # 커서가 2번째거 가리킴
# 지정 row 선택
# print(c.fetchmany(size=4)) # 커서가 6번째 거 가리킴
# 전체 row 선택
# print(c.fetchall())
# print(c.fetchone())

# 순회1
# rows = c.fetchall()
# for row in rows:
#     print('usage1 >', row)

# 순회2
# for row in c.fetchall():
#     print('usage2 >', row)

# 순회3
# for row in c.execute("SELECT * FROM users"):
#     print('usage3 >', row)

# 조건 조회1
param1 = (1, )
c.execute("SELECT * FROM users WHERE id=?", param1)
print(c.fetchall())

# 조건 조회2
param2 = '1'
c.execute("SELECT * FROM users WHERE id='%s'" % param2) # %s, %d, %f, %o
print(c.fetchall())

# 조건 조회3
c.execute("SELECT * FROM users WHERE id=:id", {'id': 1})
print(c.fetchall())

# 조건 조회4
param4 = (1, 4)
c.execute("SELECT * FROM users WHERE id IN (?, ?)", param4)
print(c.fetchall())

# 조건 조회2
c.execute("SELECT * FROM users WHERE id=:id1 OR id=:id2", {'id1': 1, 'id2': 4})
print(c.fetchall())

# dump
with conn: # 다 하면 알아서 close 됨
    # Dump 출력(DB가 사라져도 이걸 보고서 다시 복구할 수 있다
    with open('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/data/test.dump', 'w') as f:
        for line in conn.iterdump():
            f.write('%s\n' % line)
        print('Dump Write Complete!')
