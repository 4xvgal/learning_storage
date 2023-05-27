##반지름 입력받은 후 면적과 둘래를 출력
print("피자의 반지름을 입력하세요 (cm)")
radius = float(input())
area = 3.14 * radius **2
round = 3.14 * 2 * radius
print("피자의 면적은", f"{area:.2f}", "둘레는", f"{round:.2f}")