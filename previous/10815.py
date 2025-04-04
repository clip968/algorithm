import sys
input = sys.stdin.readline
N = int(input())
numberCard = list(map(int, input().split()))
M = int(input())
arr = list(map(int, input().split()))

# dict = {}

# for i in numberCard:
#     dict[i] = 0
    
# for i in range(M):
#     if arr[i] not in dict:
#         print(0, end=' ')
#     else:
#         print(1, end=' ')
numberCard.sort()

def binary_research(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None

for i in range(M):
    if binary_research(numberCard, arr[i], 0, N - 1) is not None:
        print(1, end=' ')
    else:
        print(0, end=' ')
        
