stack = []
max_size = 10

def isFull(stack):
    return len(stack) == max_size

def isEmpty(stack):
    return len(stack) == 0

def push(stack, item):
    if isFull(stack):
        print("스택이 가득 찼습니다.")
    else:
        stack.append(item)
        print("데이터가 추가되었습니다.")
        
def pop(stack):
    if isEmpty(stack):
        print('스택이 비어 있습니다.')
        return None
    else:
        return stack.pop()