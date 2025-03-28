def draw(n):
    if n == 3:
        return ['***', '* *', '***']
    
    array = draw(n // 3)
    star = []
    
    for i in array:
        star.append(i * 3)
    for i in array:
        star.append(i + ' ' * (n // 3) + i)
    for i in array:
        star.append(i * 3)
        
    return star

n = int(input())
print('\n'.join(draw(n)))