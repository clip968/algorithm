import sys
input = sys.stdin.readline

N = int(input())
array = list(map(int, input().split()))
array_new = sorted(set(array))
dic = {array_new[i] : i for i in range(len(array_new))}

for i in array:
    print(dic[i], end=' ')


