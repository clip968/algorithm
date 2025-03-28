def ref(n):
    if n == 1:
        return '-'
    
    left_side = ref(n // 3)
    blank = ' ' * (n // 3)
    return left_side + blank + left_side

while True:
    try:
        n = int(input())
        print(ref(3 ** n))
    except:
        break
        