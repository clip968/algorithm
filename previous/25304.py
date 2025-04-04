x = int(input())
num = int(input())
result = 0
for i in range(num):
    a, b = map(int, input().split())
    result += a * b

if result == x:
    print("Yes")
else:
    print("No")