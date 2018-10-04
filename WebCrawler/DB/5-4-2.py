import pymysql

# MYSQL Connection
conn = pymysql.connect(host='localhost', user='python', password='Zxcxzc', db='python_app1', charset='utf8')

try:
    with conn.cursor() as c: # conn.cursor(pymysql.cursors.DictCursor) 딕셔너리 형태로 반환해줌.
        c.execute("SELECT * FROM users")
        # 1개 row
        # print(c.fetchone())
        # 선택 지정
        # print(c.fetchmany(3))
        # 전체 row
        # print(c.fetchall())

        # 순회 1
        c.execute("SELECT * FROM users ORDER BY id ASC")
        rows = c.fetchall()
        for row in rows:
            print('usage 1>', row)

        # 순회 2
        c.execute("SELECT * FROM users ORDER BY id DESC")
        for row in c.fetchall():
            print('usage 2>', row)

        # 조건 조회 1
        param1 = (1, )
        c.execute("SELECT * FROM users WHERE id=%s", param1)
        print('param1', c.fetchall())

        # 조건 조회 2
        param2 = 1
        c.execute("SELECT * FROM users WHERE id='%d'" % param2) # python formatting : %s, %f, %d, %o
        print('param2', c.fetchall())

        # 조건 조회 3
        param3 = (4, 5)
        c.execute("SELECT * FROM users WHERE id IN (%s, %s)", param3)
        print('param3', c.fetchall())

        # 조건 조회 4
        param3 = (4, 5)
        c.execute("SELECT * FROM users WHERE id IN ('%d', '%d')" % (4, 5))
        print('param4', c.fetchall())
finally:
    conn.close()
