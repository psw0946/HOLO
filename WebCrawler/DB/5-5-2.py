import pandas_datareader.data as web
import pandas as pd
import datetime
import sqlite3
# pandas, pandas_datareader, sqlalchemy

try:
    with sqlite3.connect('C:/Users/PSW/Desktop/HOLO/WebCrawler/DB/databases/sqlite2.db') as conn:
        # 조회 시작 & 마감 날짜
        start = datetime.datetime(2018, 2, 1)
        end = datetime.datetime(2018, 3, 3)

        # google 정보 호출(지금은 안됨)
        gs = web.DataReader('KRX: 090430', 'google', start, end) # 아모레퍼시픽 주가 읽기
        # 데이터 출력
        print(gs)
        # 인덱스 출력
        print(gs.index)
        # Column 출력
        print(gs['Open'])
        # Row 출력
        print(gs.ix['2018-03-02'])

        # Index to Column
        gs['Date'] = gs.index

        # 인덱스 재설정
        gs.index = range(1, len(gs.index) + 1)

        # pandas to Database(to_sql) 지금까지는 테이블 직접 만들어서 한 줄 한 줄 삽입했으나 한 번에 만들어버리기
        gs.to_sql("AMOLE", conn, if_exists='replace', index=True, index_label='id') # fail(기존 있으면 아무것도 안함), replace(기존 데이터 삭제하고 대체), append(기존 데이터 뒤에 추가)

        conn.commit()

        # pandas read Database(read_sql) 전체조회
        df = pd.read_sql(('SELECT * FROM AMOLE'), conn) # index_col = 'id'

        # pandas read Database(read_sql) 조건조회
        df = pd.read_sql('SELECT * FROM "AMOLE" WHERE id=? OR id=?', conn, params=(3, 7), index_col='id')
finally:
    print("Dataframe SQL Work Complete!")
