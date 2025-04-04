a = input()
array = []
result = 1
for i in a:
    array.append(int(i))

array.sort()

for i in range(len(array)):
    if array[i] == 0:
        continue
    result *= array[i]
    
print(result)