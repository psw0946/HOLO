class NameTest:
    total = 0

print(dir()) # 문서의 namespace 확인
print("before: ", NameTest.__dict__)
NameTest.total = 1
print("after: ", NameTest.__dict__)

n1 = NameTest()
n2 = NameTest()
print(id(n1), "vs", id(n2))
print(dir())

print(n1.__dict__)
print(n2.__dict__)

n1.total = 77
print(n1.__dict__)

print(n1.total) # 자기 인스턴스 영역 안에 해당 키가 있기 때문에
print(n2.total) # 자기 인스턴스 영역 안에 해당 키가 없어서 클래스 영역으로 검색
