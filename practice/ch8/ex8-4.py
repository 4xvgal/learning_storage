#ex8-4.py

print("8-4 20203103 임정민")

partyA = set(["Park", "Kim", "Lee"])
partyB = set(["Park","Choi"])

print("파티 A, B 에 참석한 사람들 : ",end = ' ')
for i in partyA.union(partyB):
    print(i,end=' ')

print("\n파티 A, B 에 중복 없이 참석한 사람들 : ",end = ' ')
for j in partyA.intersection(partyB):
    print(j,end = ' ')

print("\n파티 A에만 참석한 사람 : ", end =' ')
for k in partyA.difference(partyB):
    print(k,end = ' ') 