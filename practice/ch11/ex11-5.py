#ex11-5.py
print('11-5 20203103 임정민')
import numpy as np
from matplotlib import pyplot as plt

years=[1965, 1975, 1985, 1995, 2005, 2015]
ko=[130, 650, 2450, 11600, 17790, 27250]
jp=[890, 5120, 11500, 42130, 40560, 38780]
ch=[100, 200, 290, 540, 1760, 7940]

x_range=np.arange(len(years))
plt.title("GDP per capita, 20203103,jeongmin lim")
plt.ylabel("dollars")
plt.xlabel("years")
plt.bar(x_range + 0.0,ko, width=0.25)
plt.bar(x_range + 0.3,jp, width=0.25)
plt.bar(x_range +0.6,ch, width=0.25)
plt.xticks(range(len(years)), years)
plt.show()
