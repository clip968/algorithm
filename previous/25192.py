n = int(input())
array = set()
result = 0

for i in range(n):
    user = input()
    if user != 'ENTER':
        if user not in array:
            array.add(user)
            result += 1
    else:
        array.clear()

print(result)
    