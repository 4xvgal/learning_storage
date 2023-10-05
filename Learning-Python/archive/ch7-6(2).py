print("7-6 20203103 임정민")
fruit_list=["banana", "orange", "kiwi", "apple","melon"]
max_len =0

new_list= []
for i in fruit_list:
    if max_len < len(i):
        max_len = len(i)

for j in fruit_list:
    if len(j) != max_len:
        new_list.append(j)

print(new_list)