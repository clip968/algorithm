n, m = map(int, input().split())
dict = {}

cnt = 0

for i in range(n):
    a = input()
    dict[a] = 0
    
for i in range(m):
    check = input()
    if check in dict:
        cnt += 1



print(cnt)