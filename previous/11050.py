import math


n, m = map(int, input().split()) 
hi = max(n, m)
mi = min(n, m)
result = math.factorial(hi) // (math.factorial(mi) * math.factorial(hi - mi))

print(result)