def solution(decimal):
    stack = []
    while decimal > 0:
        a = decimal % 2
        stack.append(str(a))
        decimal //= 2
    binary = ""
    while stack:
        binary += stack.pop()
    
    return binary

print(solution(13))