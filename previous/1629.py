
def func(a, b, c):
    if b == 1:
        return a % c
    else:
        if b % 2 == 0:
            return (func(a ,b // 2, c) ** 2) % c
        else:
            return (func(a, b // 2, c) ** 2 * a) % c


a, b, c = map(int,input().split())

print(func(a,b,c))