##ex 8-7.py
print("8-7 20203103 임정민")


student_tup = (('211101','조성훈','010-1234-4500'), ('211102', '김은지', '010-2230-6530'),('211103','윤소정','010-3232-7788'))

std_dict = {} ## 빈 딕셔너리 생성

c = int(0)
for i in student_tup:
    tmp = '[\'' + i[1] + '\', \'' + i[2] + '\']'
   ##tmp = "['{0}', '{1}']".format(i[1], i[2]) ##밸류로 사용할 문자열 생성
    std_dict[i[0]] = tmp ##{ 학번 : [이름, 전화번호]}

print("학생의 정보 목록")

for i in std_dict.items():
    print("{",i[0]," : ", i[1],"}") ## items로 호출해 각 index를 출력
