class SelfTest:
    def function1():
        print("function1 called!")

    def function2(self):
        print(id(self))
        print("function2 called!")

f = SelfTest()
print(dir(f))
print(id(f)) # 위 함수의 self의 주소값과 같음!

#f.function1() # 에러
f.function2() # 괄호 안에 self로 자기 자신의 주소값이 넘어가고 있던 거임!

print(SelfTest.function1()) # 인스턴스화 시키지 않고 직접 호출하면 나옴
