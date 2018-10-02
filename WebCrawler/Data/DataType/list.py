# a = 'hello'
# print(type(a))
# print(a[0])
# print(a[0:3])
# print(a[-1:])
#
# for t in a:
#     print(t)
#     print(type(t))


# 리스트 자료형(순서 O, 중복 O, 수정 O, 삭제 O)

# 선언
a = []
b = list()
c = [0, 0, 1, 2]
d = [0, 1, 'car', 'apple', 'apart']
e = [0, 1, ['car', 'apple', 'apart']]

# 인덱싱
print("#=======================#")
print('d -', type(d), d)
print('d -', d[1])
print('d -', d[0] + d[1] + d[1])
print('e -', e[-1][1])
print('e -', e[2][1])

# 슬라이싱
print("#=======================#")
print('d -', d[0:3])
print('d -', d[2:])

# 연산
print("#=======================#")
print('c + d', c + d)
print('c * 3', c * 3)
print('hi + c[0]', 'hi' + str(c[0]))

# 리스트 수정, 삭제
print("#=======================#")
c[0] = 4
print('c -', c)
c[1:2] = ['a', 'b', 'c']
print('c -', c)
c[1] = ['a', 'b', 'c']
print('c -', c)
c[1:3] = [] # 없어짐
print('c -', c)
del c[3]
print('c -', c)

# 리스트 함수
a = [5, 2, 3, 1, 4]
print("#=======================#")
print('a -', a)
a.append(6)
print('a -', a)
a.sort()
print('a -', a)
a.reverse()
print('a -', a)
print('a -', a.index(4), a[4])
print('a -', a.count(3)) # 자주 사용
a.remove(2) # index 2가 아니라 값이 2인 것을 삭제...
# remove 할 때 리스트이기 때문에 앞으로 당겨오는 O(n)의 시간 복잡도
print('a -', a)
print('a -', a.pop()) # 마지막 거를 빼고 return
print('a -', a)
ex = [8, 9]
a.extend(ex)
print('a -', a)

# 리스트 삭제 : del, remove, pop

while a:
    l = a.pop()
    print(l is 4)

