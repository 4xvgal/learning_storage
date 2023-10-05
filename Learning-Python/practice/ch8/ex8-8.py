##ex 8-8.py
#문자와 숫자로 이루어진 코드 추출하기
print("8-8 20203103 임정민")


student_tup = (('211101','조성훈','010-1234-4500'), ('211102', '김은지', '010-2230-6530'),('211103','윤소정','010-3232-7788'))

std_dict = {} ## 빈 딕셔너리 생성

c = int(0)
for i in student_tup:
    tmp = '[\'' + i[1] + '\', \'' + i[2] + '\']' # 이름과 전화번호는 튜플이 되어 딕셔너리에 삽입된다.
   ##tmp = "['{0}', '{1}']".format(i[1], i[2]) ##밸류로 사용할 문자열 생성
    std_dict[i[0]] = tmp ##{ 학번 : [이름, 전화번호]}

searchingID = input("학번을 입력하시오 : ")

resultString = std_dict[searchingID].split(',') ##rs
resultName = resultString[0]
resultTel =resultString[1]

resultName = resultName.strip('[') #양측에서 '[' 을 제거한다.
resultName = resultName.strip("'")
resultName = resultName.strip(" ")


resultTel= resultTel.strip(' ')
resultTel = resultTel.strip(']')
resultTel = resultTel.strip("'")
resultTel= resultTel.strip(' ')


print("이름 :",resultName)
print("연락처 :",resultTel)