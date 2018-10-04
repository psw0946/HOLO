import pymysql

# MYSQL Connection
conn = pymysql.connect(host='localhost', user='python', password='AXZc0', db='python_app1', charset='utf8')

try:
    with conn.cursor() as c:
        # 데이터 수정 1
        c.execute("UPDATE users SET username = %s WHERE id=%s", ('niceman', 1))
        # 데이터 수정 2
        c.execute("UPDATE users SET username = '%s' WHERE id='%d'" % ('goodboy', 2))

        # 중간 데이터 확인 1
        c.execute("SELECT * FROM users ORDER BY id DESC")
        for row in c.fetchall():
            print('check1 >', row)

        # 데이터 삭제 1
        c.execute("DELETE FROM users WHERE id=%s", (1, ))
        # 데이터 삭제 2
        c.execute("DELETE FROM users WHERE id='%s'" % (2, ))

        # 중간 데이터 확인 2
        c.execute("SELECT * FROM users ORDER BY id DESC")
        for row in c.fetchall():
            print('check2 >', row)

    conn.commit()
finally:
    conn.close()