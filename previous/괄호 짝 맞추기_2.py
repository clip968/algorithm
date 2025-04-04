def solution(s):
    stack = []
    for i in s:
        if i == '(':
            stack.append(i)
        elif stack and i == ')':
            stack.pop()
        
    if stack:
        return False
    else:
        return True

print(solution('((())()'))