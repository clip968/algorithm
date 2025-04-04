n = int(input())
array = {'ChongChong'}

for i in range(n):
    first, second = input().split()
    
    if first in array:
        array.add(second)
    
    if second in array:
        array.add(first)

print(len(array))