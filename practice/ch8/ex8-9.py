##ex 8-9.py
print("8-9 20203103 임정민")

student_tup = (('211101','조성훈','010-1234-4500', '4.3'), ('211102', '김은지', '010-2230-6530','3.9'),('211103','윤소정','010-3232-7788','4.25'))
std_dict = {} ## 빈 딕셔너리 생성

def cleanStr(s): ##문자열에서 특수기호 제거
    s = s.strip()
    s = s.strip("[")
    s = s.strip("]")
    s = s.strip('\'')
    s = s.strip("'")
    return s

for i in student_tup:
    ##tmp = '[\'' + i[1] + '\', \'' + i[2] + '\',' 
    tmp = "['{0}', '{1}', '{2}']".format(i[1], i[2], i[3]) ##밸류로 사용할 문자열 생성
    std_dict[i[0]] = tmp ##{ 학번 : [이름, 전화번호, 학점]}

resultName = []
resultTel = []
resultScore = []
resultID = []


c = int(0)
des = int(len(std_dict))
for i in std_dict:
    resultString = std_dict[i].split(',')
    resultID.append(i)
    resultName.append(cleanStr(resultString[0]))
    resultTel.append( cleanStr(resultString[1]))
    resultScore.append( cleanStr(resultString[2]))

sum = float(0)
avg = float(0)
for i in range(c,des):
    sum = sum + float(resultScore[i]) ## 합계
   
avg = sum / float(des) ## 평균 저장

for i in range(c,des):
    print('{' + "\'{0}\' : [\'{1}\', \'{2}\', {3}]".format(resultID[i],resultName[i],resultTel[i],resultScore[i]) + '}')
print("전체 학생의 학점 평균 : ", round(avg, 2))