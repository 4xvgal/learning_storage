#ex11-1.py
print('\n11-1.  20203103 임정민 \n')
import matplotlib.pyplot as plt
import numpy as np

np.random.seed(0)
x = [x for x in range(1000)]
y = np.random.rand(1000)
plt.title("Numbers (20102000, Hong, Kil DOng)")
plt.plot(x, y, 'r-', marker='o')

plt.show()
