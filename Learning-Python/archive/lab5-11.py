import random
tries = 0
guess = 0
answer = random.randint(1, 100)
print("1 부터 100 사이의 숫자를 맞추십시오")
while guess != answer:
   guess = int(input("숫자를 입력하시오"))
   tries = tries + 1
   if answer < guess:
      print("높음")
   elif answer > guess:
      print("낮음")
      
print("축하합니다. 총 시도횟수 = ", tries)