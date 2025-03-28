import sys
input = sys.stdin.readline
n = int(input())
list_A = list(map(int, input().split()))
m = int(input())
list_B = list(map(int, input().split()))

check = {}

for i in list_A:
    check[i] = 1
    
for i in list_B:
    try:
        if check[i] == 1:
            print("1")
            
    except:
        print("0")
    