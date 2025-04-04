import sys
input = sys.stdin.readline
x = 0
y = 0
square = list(map(int, input().split()))

x = min(square[0] - 0, square[2] - square[0])
y = min(square[1] - 0, square[3] - square[1])
    
result = min(x, y)

print(result)