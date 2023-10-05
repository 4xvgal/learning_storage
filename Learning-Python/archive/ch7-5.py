##ch7-6.py
print ('7-5 20203103 임정민')

list_char = ('A', 'B', 'C')
list_intc = ('1',2)

output = []
for i in list_char:
    for j in list_intc:
        output.append((i + str(j)))

print (output)