array = [0] * 31
for i in range(28):
    n = int(input())
    array[n] = n

for i in range(1, 31):
    if array[i] != i:
        print(i)