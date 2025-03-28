import sys, math
input = sys.stdin.readline

a, b = map(int, input().split())
c, d = map(int, input().split())

up = a * d + c * b
down = b * d

best = math.gcd(up, down)

up //= best
down //= best

print(up, down)