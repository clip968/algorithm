array = [[0 for i in range(15)] for j in range(5)]

for i in range(5):
    x = list(map(str, input()))
    for j in range(len(x)):
        array[i][j] = x[j]
    
for i in range(15):
    for j in range(5):
        if array[j][i] != 0:
            print(array[j][i], end='')