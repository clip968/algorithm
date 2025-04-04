x = int(input())

paper = [[0] * 101 for i in range(101)]

for i in range(x):
    a, b = map(int, input().split())
    for i in range(10):
        for j in range(10):
            paper[a + i][b + j] = 1

result = 0

for i in paper:
    result += sum(i)
    
print(result)
