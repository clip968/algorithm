a, b = map(int, input().split())
c = int(input())
d = (c + b) // 60
if d >= 1:
    a += d
    b = (b + c) - 60 * d
    if a >= 24:
        a = a - 24
else:
    b += c
    
print(a, b)
    