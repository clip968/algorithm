n = int(input())
travler = list(map(int, input().split()))
travler.sort()
count = 0
result = 0

for i in travler:
    count += 1
    if count >= i:
        result += 1
        count = 0
print(result)
    