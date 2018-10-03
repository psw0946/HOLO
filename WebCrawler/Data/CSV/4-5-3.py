import pandas as pd
import numpy as np

# 랜덤으로 DataFrame 생성
# df = pd.DataFrame(np.random.randint(0, 100, size=(100, 4)), columns=list('ABCD'))
df = pd.DataFrame(np.random.randn(100, 4), columns=['ONE', 'TWO', 'THREE', 'FOUR'])
print(df)

# df.to_csv('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/result_s3.csv', index=False)
df.to_csv('C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/CSV/result_s3.csv', index=False, header=False) # 헤더는 포함 안됨
