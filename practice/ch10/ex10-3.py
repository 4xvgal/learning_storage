#ex10-3.py
import numpy as np


print(' 10-8 20203103 임정민')
array_a = np.random.rand(3,3,3)
print('1)배열 a : \n',array_a)


print('2)의 원소들중 최댓값:', np.max(array_a))
print('3)의 원소들 중 최댓값의 위치:',np.argmax(array_a))