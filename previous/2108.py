import statistics as st


n = int(input())
array = []

for i in range(n):
    array.append(int(input()))
    
array.sort()

print(round(st.mean(array)))
print(st.median(array))

dic = {}
for i in array:
    if i in dic:
        dic[i] += 1
    else:
        dic[i] = 1
        
a = max(dic.values())
macx = []

for j in dic:
    if a == dic[j]:
        macx.append(j)
    
if len(macx) > 1:
    print(macx[1])
else:
    print(macx[0])
    
print(max(array) - min(array))