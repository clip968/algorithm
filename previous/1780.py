import sys
input = sys.stdin.readline
def papers(x, y, n):
    global m_one, zero, one
    fdig = arr[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if fdig != arr[i][j]:
                papers(x, y, n//3)
                papers(x, y+n//3, n//3)
                papers(x+n//3, y, n//3)
                papers(x+n//3, y+n//3, n//3)
                papers(x+(n//3*2), y, n//3)
                papers(x+(n//3*2), y+(n//3*2), n//3)
                papers(x, y+(n//3*2), n//3)
                papers(x+n//3, y+(n//3*2), n//3)
                papers(x+(n//3*2), y+n//3, n//3)
                return
    if fdig == -1:
        m_one += 1
    elif fdig == 0:
        zero += 1
    else:
        one += 1
    
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

m_one, zero, one = 0, 0, 0
fdig = 0

papers(0, 0, n)
print(m_one)
print(zero)
print(one)
