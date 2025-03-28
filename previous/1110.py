n = int(input())
result = n
count = 1

while True:
    
    a = result // 10
    b = result % 10
    plus = a + b    
    result = (b * 10) + (plus % 10)
    if result == n:
        break
    count += 1
    
print(count)