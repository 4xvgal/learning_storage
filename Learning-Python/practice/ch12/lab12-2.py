print('\n12-7. 20203103임정민 \n')
import pandas as pd
import matplotlib.pyplot as plt 
weather = pd.read_csv('bin\weather.csv', encoding='CP949')
monthly = [ None for x in range(12) ]
monthly_temp = [ 0 for x in range(12) ]
weather['month'] = pd.DatetimeIndex(weather['일시']).month 

for i in range(12) :
    monthly[i] = weather[ weather['month'] == i + 1 ] 
    # old version에서 가능 # monthly_temp[i] = monthly[i].mean()['평균기온']
    monthly_temp[i] = monthly[i]['평균기온'].mean()
plt.title('12-7. 20203103, LimJeongMin')
plt.plot(monthly_temp, 'red')
plt.xticks(range(0,12), range(1,13))
plt.show()
