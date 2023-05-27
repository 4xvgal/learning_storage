print("7-4 20203103 임정민")

list = []
pop = '1'
max_pop = 0
min_pop = 999999999
max_city = 0
min_city = 0
total_pop = 0
while 1:
    name, pop = (input("도시명, 인구를 입력하세요: ").split())
    if name == '0' and pop == '0':
        break
    list.append((name,int(pop)))
print(list)

for i in list:
    total_pop += i[1]
    if i[1] > max_pop:
        max_pop = i[1]
        max_city = i
    if i[1] < min_pop:
        min_pop = i[1]
        min_city = i

print('최대인구: {0}, 인구: {1} 천명'.format(max_city[0],max_city[1]))
print('최소인구: {0}, 인구: {1} 천명'.format(min_city[0],min_city[1]))
print('평균 인구: {0} 천명'.format(total_pop/len(list)))

