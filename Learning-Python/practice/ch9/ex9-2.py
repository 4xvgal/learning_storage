
print('\n9-2.  20203103 임정민\n')
t = "It's Not The Right Time To Conduct Exams. MY DEMAND IN BOLD AND CAPITAL. NO EXAMS IN COVID!!!"
tcount = 0
count = 0

print('느낌표 개수 :', t.count('!'))
for ch in t:
    tcount+=1
    if ch.isupper():
        count += 1
print('총 문자 개수 :', tcount)
print('대문자 개수 :', count)
