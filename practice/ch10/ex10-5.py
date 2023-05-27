#ex10-5.py
import numpy as np

print('10-9 20203103 임정민')
a = np.arange(0,32).reshape(4,4,2)

print(a)

b = a.flatten()


print('a :',a)
print('b :', b)
print('10번째 원소 :', b[9])
print('20번째 원소 :', b[19])
