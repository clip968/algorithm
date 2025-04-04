n = int(input())

for i in range(n):
    stack = []  
    m = input()
    for j in m:
        if j == '(':
            stack.append(j)
        elif j == ')':
            if stack:
                stack.pop()
            else:
                print("NO")
                break

    else:
        if not stack:
            print("YES")
        else:
            print("NO")