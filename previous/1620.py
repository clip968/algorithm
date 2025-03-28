n, m = map(int, input().split())
dicts = {}

for i in range(1, n + 1):
    dicts[i] = input()
reversedicts = dict(map(reversed, dicts.items()))
for j in range(m):
    check = input()
    try:
        check = int(check)
        print(dicts[check])
    except:
        print(reversedicts[check])