N = int(input())
arr = list(set(input() for i in range(N)))

arr.sort(key=lambda x: (len(x), x))

for i in range(len(arr)):
    print(arr[i])