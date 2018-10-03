from pandas import Series, DataFrame

r_data = {'City': ['서울', '대구', '부산', '대전'], 'Total1': [55000, 49000, 52000, 50000], 'Total2': [65000, 59000, 62000, 60000]}
i_data = ['one', 'two', 'three', 'four']

# 출력1
print(r_data)
print(i_data)

# DataFrame 정의
d_frame = DataFrame(r_data, index=i_data)
print(type(d_frame))
print(d_frame)
print(d_frame.index)
print(d_frame.values)
print(d_frame['City']) # Columns
print(d_frame.ix['one']) # Rows
# print(type(d_frame.ix['one'])) --> Series

# 값 순회
for e in d_frame.values:
    for i, z in enumerate(e):
        print(i, z)
