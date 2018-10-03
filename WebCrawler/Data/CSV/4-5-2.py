import pandas as pd

# 읽기
df2 = pd.read_csv('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/csv_s2.csv', sep=';', skiprows=[0], header=None, names=["Name", 'Test1', 'Test2', 'Test3', 'Final', 'Grade']) # sep는 구분자
# print(df)

# 컬럼 내용 변경
# print(df2['Grade'])
# df2['Grade'] = df2['Grade'].str.replace('C', 'A++')
# print(df2)

# 평균 컬럼 추가
df2['Avg'] = df2[['Test1', 'Test2', 'Test3', 'Final']].mean(axis=1) # 1은 x방향(가로), 0은 y방향(세로)
# print(df2)

# 합계 컬럼 추가
df2['Sum'] = df2[['Test1', 'Test2', 'Test3', 'Final']].sum(axis=1) # 1은 x방향(가로), 0은 y방향(세로)
print(df2)

# df2.to_csv('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/result_s2.csv') 인덱스 추가돼서 저장됨(가장 왼쪽 컬럼)
df2.to_csv('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/result_s2.csv', index=False)
