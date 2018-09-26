class UserInfo:
    def set_info(self, name, phone):
        self.name = name
        self.phone = phone

    def print_info(self):
        print("-------------")
        print("Name: " + self.name)
        print("Phone: " + self.phone)
        print("-------------")

user1 = UserInfo()
user2 = UserInfo()

#print(id(user1)) # 참조하는 어드레스가 나옴
#print(id(user2))

user1.set_info("kim", "010-3433-7777")
user2.set_info("park", "010-7777-7777")

#user1.print_info()
#user2.print_info()

print(user1.__dict__) # Dictionary 형태로 성질들 가져옴
print(user2.__dict__)

print(user1.name)
print(user1.phone)
