# 튜플 자료형(순서 O, 중복 O, 수정 X, 삭제 X) : 불변(읽기 전용)
# 속도: 튜플 > 리스트

# 선언
a = ()
b = (0, ) # 원소 1개 선언할 때는 반드시 , 를 붙인다. (안 그러면 int로 인식)
c = (0, 1, 2, 3)
d = (0, 1, 'car', 'apple', 'apart')
e = (0, 1, ('car', 'apple', 'apart'))

# 인덱싱
print('#===============#')
print('d -', type(d), d)
print('d -', d[1])
print('d -', d[0] + d[1] + d[1])
print('d -', d[-1])
print('e -', e[-1][1])
print('e -', e[-1][1][4])
print('e -', list(e[-1][1])) # 리스트로 변형 가능

# 슬라이싱
print('#===============#')
print('d -', d[0:3])
print('d -', d[2:])
print('e -', e[2][1:3])

# 튜플 연산
print('#===============#')
print('c + d -', c + d)
print('c * 3 -', c * 3)
print('hi + c[0] -', 'hi' + str(c[0]))

# 튜플 함수. 삭제 없음. append 없음.
a = (5, 2, 3, 1, 4)

print('a -', a)
# print('a -', a[5])
print('a -', a.index(5))
print('a -', a.index(4))
print('a -', a.count(4))
