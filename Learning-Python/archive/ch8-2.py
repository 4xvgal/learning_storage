##8.2 py


student_dic= {}

for student in student_dic:
    number, name, phone = student
    student_dic[number] = [name,phone]

number = input("학번을 입력하시오:")
print('이름 :', student_dic[number][0])
print('이름 :', student_dic[number][1])
