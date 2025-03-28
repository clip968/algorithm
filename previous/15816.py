import sys

input = sys.stdin.readline

n = int(input())
quest = list(map(int, input().split()))
array = {}

for i in quest:
    array[i] = i

m = int(input())

for i in range(m):
    addon = list(map(int, input().split()))
    if addon[0] == 1:
        array[addon[1]] = addon[1]
    elif addon[0] == 2:
        a, b = addon[1], addon[2]  
        count = 0
        for j in range(a, b + 1):
            if j not in array:
                count += 1
        print(count)