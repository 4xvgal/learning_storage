print('\n12-2. 20203103 임정민 \n')
import csv     
f = open('bin/weather.csv')  
data = csv.reader(f)             
header = next(data)

min_temp = 0.0
for row in data:             
    if row[1] == '' :
        temp = 100
    else :
        temp = float(row[1])
        if min_temp > temp :    
            min_temp = temp         
print('지난 10년간 울릉도의 최소 온도는 ', min_temp, '도')
