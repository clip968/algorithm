from collections import deque
import sys
input = sys.stdin.readline
n  = int(input())
result = deque()

for i in range(n):
    command = list(map(int, input().split()))
    if command[0] == 1:
        result.appendleft(command[-1])
    
    elif command[0] == 2:
        result.append(command[-1])
    
    elif command[0] == 3:
        if result:
            print(result.popleft())
        
        else:
            print(-1)
        
    elif command[0] == 4:
        if result:
            print(result.pop())
        
        else:
            print(-1)
        
    elif command[0] == 5:
        print(len(result))
    
    elif command[0] == 6:
        if result:
            print(0)
        
        else:
            print(1)
        
    elif command[0] == 7:
        if result:
            print(result[0])
        
        else:
            print(-1)
        
    elif command[0] == 8:
        if result:
            print(result[-1])
        
        else:
            print(-1)
        
            
    