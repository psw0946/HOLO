class UserInfo:
    def __init__(self, name, phone):
        self.name = name
        self.phone = phone

    def print_info(self):
        print("-------------")
        print("Name: " + self.name)
        print("Phone: " + self.phone)
        print("-------------")

    def __del__(self): # 메모리 삭제될 때 단 한 번 실행되는 함수
        print("delete!")

user1 = UserInfo("kim", "010-3433-7777")
user2 = UserInfo("park", "010-7777-7777")


