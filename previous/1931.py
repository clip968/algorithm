n = int(input())

meeting = []

for i in range(n):
    start, end = map(int, input().split())
    meeting.append((start, end))

meeting.sort(key= lambda x: (x[1], x[0]))

time, result = 0, 0
for i in meeting:
    if time <= i[0]:
        time = i[1]
        result += 1

print(result)