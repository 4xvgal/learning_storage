print('\n12-1. 20203103 임정민 \n')
import csv     
f = open('bin/weather.csv') ##D 파티션이 없는 관계로 임시 폴더에 넣어 실행하였습니다. 
data = csv.reader(f)
i=11
for row in data:
    print(row)
    i=i-1
    if(i==0) :
        break
f.close()
