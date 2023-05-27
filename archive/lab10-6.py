##lab10-6.py

import numpy as np

players = np.zeros((100,3))

players [:,0] = 10 * np.random.randn(100) + 175
players [:,1] = 10 * np.random.randn(100) + 70
players [:,2] = np.floor(10*np.random.randn(100)) + 22

heights = players[:,0]
print('신장 평균값:', np.mean(heights))
print('신장 중앙값:',np.median(heights))
print('신장 총계',round(np.sum(heights)))

weights = players[:,1]
print('체중 평균값:',np.mean(weights))
print('체중 중간값:',np.median(weights))
print('체중 총계',round(np.sum(weights)))

ages = players[:,2]
print('나이 평균값:',np.mean(ages))
print('나이 중간값:',np.median(ages))
print('나이 총계:',round(np.sum(ages)))