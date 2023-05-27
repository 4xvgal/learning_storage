#ex11-3.py
print('11-3 20203103 임정민')
import matplotlib.pyplot as plt
x = [x / 10 for x in range(20)]        
y = [(x / 10)**2 for x in range(20)]   
z = [(x / 10)**3 for x in range(20)]   
i = [2**(x / 10) for x in range(20)]   

plt.title('20203103, jeongmin lim')
plt.plot(x, x, label='linear')
plt.plot(x, y, label='quadratic')
plt.plot(x, z, label='qubic')
plt.plot(x, i, label='power')

plt.xlabel('x label')   
plt.ylabel('y label')

plt.legend()           
plt.show()
