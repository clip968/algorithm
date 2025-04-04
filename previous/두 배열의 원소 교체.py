n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

new_a = sorted(a)
new_b = sorted(b, reverse=True)

for i in range(k):
    if new_a[i] < new_b[i]:
        new_a[i], new_b[i] = new_b[i], new_a[i] 

result = sum(new_a)
print(result)

