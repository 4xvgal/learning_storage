print('\n12-4. 20203103 임정민 \n')
import pandas as pd 
df = pd.read_csv('bin\countries.csv', index_col = 0)
print(df.head())
print('\n', df.tail())
print('\n', df[3:6]) # 3, 4, 5
