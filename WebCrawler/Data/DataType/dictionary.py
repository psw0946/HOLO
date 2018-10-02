# 딕셔너리 자료형 (Key, Value) -> (순서 X, 중복 X, 수정 O, 삭제 O)

# 선언
a = {'name': 'kim', 'phone': '01077777777', 'birth': 910809}
b = {0: 'Hello World!'}
c = {'arr': [0, 1, 2, 3]}
print(type(a), a)

# 출력
print('a -', a['name']) # key 없는 것 가져올 경우 Error
print('a -', a.get('name')) # 없으면 None
print('c -', type(c.get('arr')))

# 딕셔너리 추가
a['address'] = 'Seoul'
print('a -', a)
a['rank'] = [1, 2, 3]
print('a -', a)

print('a -', list(a.keys()))
print('a -', a.keys())

print('a -', list(a.values()))
print('a -', a.values())

print('a -', a.items()) # (key, value)를 튜플로

print('a -', 'name' in a) # key가 있는지 검사
print('a -', 'city' in a)
