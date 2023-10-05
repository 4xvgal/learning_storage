##ex 8-6.py
print("8-6 20203103 임정민")


fruits_dic = {'사과':0, '배': 0, '수박':0, '귤': 0, '포도':0}
fruits_list = ['사과', '배', '수박', '귤', '포도']
frStr = input ("사과, 배, 수박, 귤, 포도 가격을 공백으로 구분하여 입력:",)

frStr_split = frStr.split(' ')


for i in range(len(fruits_dic)):
    fruits_dic[str(fruits_list[i])] = frStr_split[i]


print("-----------------오늘의과일가격-------------")
for m in fruits_dic.items():
    print("{0} : {1} 원".format(m[0],m[1]))


while True:
    st = input("구매를 원하시는 과일의 이름을 입력하시오 (종료 q) :")
    if st == 'q':
        break
    print("오늘의 {0} 가격은 {1}원 입니다.".format(st,fruits_dic[st]))

