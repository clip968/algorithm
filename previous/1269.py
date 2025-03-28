n, m = map(int, input().split())
a = set(map(int, input().split()))
b = set(map(int, input().split()))

first = a - b
second = b - a

result = len(first) + len(second)

print(result)