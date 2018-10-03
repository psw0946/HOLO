import pandas as pd

df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx', header=0)
# print(df)

# 컬럼 값 수정
# df['State'] = df['State'].str.replace(' ', '|') # 공백을 |로 바꿈
# print(df)

# 평균 컬럼 추가
df['Avg'] = df[['2003', '2004', '2005']].mean(axis=1).round(2)
# print(df)

# 합계 컬럼 추가
df['Sum'] = df[['2003', '2004', '2005']].sum(axis=1).round(2)
# print(df)

# 최대값, 최소값 출력
# print(df[['2003', '2004', '2005']].max(axis=0)) # 각 년도의 최대값
# print(df[['2003', '2004', '2005']].min(axis=0)) # 각 년도의 최소값

# 상세 정보 출력
# print(df.describe())

df.to_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/result_s1.xlsx')
# df.to_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/result_s1.xlsx', index=None) 인덱스 제외
