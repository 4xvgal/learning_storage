#10-6.py
import numpy as np

print('10-10 20203103 임정민')


x1 = [i for i in range(100)]
x2 = [i+ np.random.randint(1,10) for i in range(100)]
x3 = [i+ np.random.randint(1,50) for i in range(100)]
x4 = [i+ np.random.randint(1,100) for i in range(100)]

result = np.corrcoef([x1,x2,x3,x4])

print('x1 :\n',x1)
print('x2:\n',x2)
print('x3:\n',x3)
print('x4:\n',x4)

print(result)