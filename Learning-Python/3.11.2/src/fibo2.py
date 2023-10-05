# filename:fibo2.py
def fibo2(n):
    global dic, sum
    if n in dic:
        ##if fibo2(n) in the dictionary. returning dic[n]
        return dic[n]
    ## 딕셔너리에 저장되어있는 n-1 과 n-2 를 합해 저장
    dic[n] = fibo2(n-1) + fibo2(n-2)
    sum = sum + 1
    return dic[n]
dic = {0:0, 1:1}
sum = int(0)

#sum을 리턴해주는 함수
def getSum():
    return sum