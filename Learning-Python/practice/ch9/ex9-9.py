print('\n9-9.  20203103 임정민 \n')
import string
src_str = string.ascii_uppercase + string.ascii_lowercase # cf. sring.ascii_letters

def cipher(a): # 암호화 코드를 만드는 함수
    idx = src_str.index(a)
    return dst_str[idx]

src = input('문장을 입력하시오 : ')
size = int(input('이동시킬 칸 수를 입력하시오 : '))
dst_str = src_str[size:] + src_str[:size]

print('암호화된 문장 : ', end='')

for ch in src:
    if ch in src_str:
        print(cipher(ch), end='')
    else:
        print(ch, end='')
