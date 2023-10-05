def fibonacci(n):
    global sum
    if n < 0:
        print("잘못된 입력입니다.")
    elif n == 1:
        sum = sum +1
        return 0
    elif n == 2:
        sum = sum +1
        return 1
    else:
        sum = sum+ 1
        return fibonacci(n-1) + fibonacci(n-2)
sum = int(0)
i = int(input("몇 번째 항: "))
print(fibonacci(i))
print("count = ", sum)
