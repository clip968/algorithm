from collections import deque

n = int(input())
paper = deque(enumerate(map(int, input().split())))
result = []

while paper:
    first, second = paper.popleft()
    result.append(first + 1)
    
    if second > 0:
        paper.rotate(-(second - 1))
    else:
        paper.rotate(-second)
        
print(' '.join(map(str, result)))
    
    