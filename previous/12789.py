n = int(input())
line = list(map(int, input().split()))
stack = []
target = 1

while line:
    if line[0] == target:
        line.pop(0)
        target += 1
    else:
        stack.append(line.pop(0))
        
    while stack:
        if stack[-1] == target:
            stack.pop()
            target += 1
        else:
            break

if not stack:
    print('Nice')
    
else:
    print('Sad')