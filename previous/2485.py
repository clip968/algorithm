import sys
import math

input = sys.stdin.readline

n = int(input())
first = int(input())
arr = []

for i in range(n - 1):
    num = int(input())
    arr.append(num - first)
    first = num

width = arr[0]
for i in range(1, len(arr)):
    width = math.gcd(width, arr[i])

result = 0
for i in arr:
    result += i // width - 1
    
print(result)