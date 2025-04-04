N = int(input())
numberCards = list(map(int, input().split()))
M = int(input())
check = list(map(int, input().split()))
dicts = {}

for i in numberCards:
    if i in dicts:
        dicts[i] += 1
    else:
        dicts[i] = 1

for i in check:
    cnt = dicts.get(i)
    if cnt == None:
        print(0, end=' ')
    else:
        print(cnt, end=' ')