##ex10-2.py

import numpy as np
n_arr = np.array([[0,1,2,3,4],
                  [5,6,7,8,9],
                  [10,11,12,13,14],
                 [15,16,17,18,19],
                 [20,21,22,23,24]])
#1)
print('1)', n_arr)
#2)
print('2)')
print('첫 원소 :',n_arr[0,0])
print('마지막 원소 :',n_arr[-1,-1])
#3)
print('3)')
n_arr2 = n_arr[:2]
print(n_arr2)

#4)
print('4)')
n_arr3 = n_arr[2:]
print(n_arr3)

#5)
print('5)')
n_arr4 = n_arr[0:,::2]
print(n_arr4)
#6)
print('6)')
n_arr5 =n_arr[::2,::2]
print(n_arr5)
#7)
print('7)')
n_arr6= n_arr[:2]
n_arr6 = np.reshape(n_arr6,(5,2))
print(n_arr6)