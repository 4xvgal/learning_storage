print("키를 입력하세요 (cm)")
height = float(input())
print("몸무게를 입력하십시오")
weight = float(input())
bmi = weight / height**2 *10000
print("bmi = "f"{bmi:.2f}")