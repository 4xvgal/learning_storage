#lab 7-5.py
import random
problems =[]

problems.append("514 * 516")
problems.append("1 + 2")
problems.append("30 - 2")
problems.append("12 * 12")
problems.append("1 + 0")
problems.append("32 - 16")
problems.append("256 * 2 + 2")
problems.append("3 + 3 * 3")
problems.append("22 - 20")

print("7-3. 20203103 임정민")
print("##############################\n#   오늘의 수학문제     #\n##############################")
i = 1
exitInteger = 1
while i <=10:
    randProblem= random.choice(problems)
    print("문제", i ,'.', randProblem,"=", eval(randProblem))
    exitInteger =  int(input("마치려면 -1, 계속하려면 1: "))
    if exitInteger == -1:
        break
    i = i + 1