fruits = []

name  = '0'
while name != '없음':
    name = input('좋아하는 과일의 이름을 입력하시오:' )
    if name != '없음':
        fruits.append(name)
fruits.sort()
print('오름 차순 정렬 :')
print(fruits)

fruits.sort(reverse=True)
print('내림 차순 정렬 :')
print(fruits)