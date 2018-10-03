import pandas as pd
# xlrd 엑셀 파일 읽기
# openpyxl 파이썬으로 엑셀 꾸미기

# 기본 읽기1
# df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx')
# df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx', sheet_name=0) # 시트 번호 지정 가능
# print(df)
# print(df.head()) # 상위 5개 데이터만
# print(df.tail()) # 하위 5개 데이터만

# 행, 푸터(Footer) 스킵
# df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx', skiprows=[0], skipfooter=10)
# print(df)

# 헤더 정의(1)
# df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx', header=0)
# print(df)
# print(list(df)) # 헤더를 리스트로
# print(list(df.columns.values))

# 헤더 정의(2)
# df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx', skiprows=[0], header=None, names=['State', 2003, 2004, 2005])
# print(df)

# 특정 값 치환
df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx', header=0, na_values='...', converters={'2003': lambda w: w if w > 60000 else None})
# print(df)
print(pd.isnull(df))

# 실습 정리 및 인덱스 재정의
df = pd.read_excel('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/excel_s1.xlsx', header=0)
# print(df)
print(df.rename(index=lambda x:x+1))
print(df.rename(index=lambda x:x+1).index)
