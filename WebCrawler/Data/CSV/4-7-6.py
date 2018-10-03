import matplotlib.pyplot as plt
import pandas_datareader.data as web
import datetime

# 조회 시작 및 종료 날짜
start = datetime.datetime(2018, 2, 1)
end = datetime.datetime(2018, 2, 17)

# 네이버 주식 정보 조회
gs_naver = web.DataReader('KRX: 035420', 'google', start, end)
# 카카오 주식 정보 조회
gs_kakao = web.DataReader('KRX: 035720', 'google', start, end)

# 출력
print(gs_naver)
print(gs_kakao)

# 윈도우 제목
fig = plt.figure('Chart Test')
# 차트 사이즈 지정
fig.set_size_inches(10, 6, forward=True) # width, height

# 차트 설정 1
plt.plot(gs_naver.index, gs_naver['Close'], 'b', label='Naver')

# 차트 설정 2
plt.plot(gs_kakao.index, gs_kakao['Close'], 'r', label='Kakao')

# 범례 위치를 지정해야 label 나옴
plt.legend(loc='upper left')
# 차트 제목
plt.title('Naver & Kakao')

# x축 레이블
plt.xlabel('Date')
# y축 레이블
plt.ylabel('Close')
