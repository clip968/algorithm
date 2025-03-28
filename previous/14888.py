import sys
input = sys.stdin.readline

n = int(input())
array = list(map(int, input().split()))
oper = list(map(int, input().split()))

maximum = -int(1e9)
minimum = int(1e9)
def dfs(cnt, result, plus, minus, multiply, divide):
    global maximum, minimum
    if cnt == n:
        maximum = max(maximum, result)
        minimum = min(minimum, result)
        return
        
    if plus > 0:
        dfs(cnt + 1, result + array[cnt], plus - 1, minus, multiply, divide)
    if minus > 0:
        dfs(cnt + 1, result - array[cnt], plus, minus - 1, multiply, divide)
    if multiply > 0:
        dfs(cnt + 1, result * array[cnt], plus, minus, multiply - 1, divide)
    if divide > 0:
        dfs(cnt + 1, int(result / array[cnt]), plus, minus, multiply, divide - 1)



dfs(1, array[0], oper[0], oper[1], oper[2], oper[3])

print(maximum)
print(minimum)




