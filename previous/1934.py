import sys, math
input = sys.stdin.readline

n = int(input())


for j in range(n):
    a, b = map(int, input().split())
    print(math.lcm(a, b))
    

            
        