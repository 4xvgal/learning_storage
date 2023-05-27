print('\n9-3.  20102000 홍길동 \n')
import random
import string
src_str = string.ascii_letters + '0123456789'
print ('src_str=', src_str, '\n')
n_digits = int(input('몇 자리의 비밀번호를 원하십니까?'))
otp = ''
for i in range(n_digits) :
    idx = random.randrange(len(src_str)) # cf. random.randrange(0, 10)
    otp += src_str[idx]
print(otp)
