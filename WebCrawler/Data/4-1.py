import pickle # (객체, 텍스트) 직렬화, 역직렬화

# 파일 이름과 데이터
bfilename = 'C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/test.bin'
tfilename = 'C:/Users/PSW/Desktop/HOLO/WebCrawler/Data/test.txt'

data1 = 77
data2 = "Hello, world!"
data3 = ['car', 'apple', 'house']

# 바이너리 쓰기
with open(bfilename, 'wb') as f:
    pickle.dump(data1, f) # dumps(문자열 직렬화), dump(객체 직렬화)
    pickle.dump(data2, f)
    pickle.dump(data3, f)

with open(tfilename, 'wt') as f:
    f.write(str(data1))
    f.write('\n')
    f.write(data2)
    f.write('\n')
    f.writelines('\n'.join(data3)) # 리스트이기 때문에 그냥 write를 하면 오류 발생

# 바이너리 읽기(자료형 보존)
with open(bfilename, 'rb') as f:
    b = pickle.load(f) # loads(문자열 역직렬화)
    print(type(b), ' Binary Read1 |', b)
    b = pickle.load(f)
    print(type(b), ' Binary Read2 |', b)
    b = pickle.load(f)
    print(type(b), 'Binary Read3 |', b)

# 텍스트 읽기(다 str 로 불러옴)
with open(tfilename, 'rt') as f:
    for i, line in enumerate(f, 1):
        print(type(line), 'Text Read' + str(i) + ' |', line, end='') # end는 끝 부분을 이렇게 처리한다는...
