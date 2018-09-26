# 클래스 변수, 인스턴스 변수

class Warehouse:
    stock_num = 0
    def __init__(self, name):
        self.name = name
        Warehouse.stock_num += 1

    def __del__(self):
        Warehouse.stock_num -= 1

user1 = Warehouse("kim")
user2 = Warehouse("park")

print(user1.name)
print(user2.name)

print(user1.__dict__)
print(user2.__dict__) # stock_num은 보이지 않음!

print(Warehouse.__dict__)
print(user1.stock_num)
print(user2.stock_num)
# 클래스 변수는 공유가 된다.
# 처음에는 자기 자신의 namespace에서 확인하고 없으면 클래스의 namespace를 찾는다
