import matplotlib.pyplot as plt

# fig 객체 생성
fig = plt.figure()

# 서브 슬롯 생성(2행 1열)
ax1 = fig.add_subplot(2, 1, 1)
ax2 = fig.add_subplot(2, 1, 2)

# x축 생성
x = range(0, 100)

# y축 생성1
y = [v*v for v in x]

# y축 생성2
z = [v*v*2 for v in x]

# 라인 차트(1행 1열)
# ax1.plot(x, y, 'b')
ax1.plot(x, y, 'b', z, 'r--')
ax1.bar(x, y)

# Bar 차트(2행 1열)
ax2.bar(x, z)

plt.show()
