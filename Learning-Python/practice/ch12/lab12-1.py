#울릉도는 몇월에 바람이 가장 강할까?
#월 평균풍속
import csv
import matplotlib.pyplot as plt
print('\n12-3. 20203103 임정민 \n')

f = open('bin/weather.csv')  
data = csv.reader(f)                      
header = next(data)                      
monthly_wind = [ 0 for x in range(12) ]   
days_counted = [ 0 for x in range(12) ]   
for row in data: 
    month = int(row[0][5:7])              
    if row[3] !=  '' :                     
        wind = float(row[3])             
        monthly_wind[month-1] += wind 
        days_counted[month-1] += 1    
for i in range(12) :
    monthly_wind[i] /= days_counted[i]   

print(monthly_wind)
plt.bar(range(len(monthly_wind)), monthly_wind)
plt.xticks(range(0,12), range(1,13))
plt.show()
f.close()          
