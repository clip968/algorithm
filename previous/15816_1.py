import sys
input = sys.stdin.readline
n = int(input())
quest = list(map(int, input().split()))
m = int(input())

def commands(command, quests, start, end):
    if command == 1:
        quests.append(start)
        quests.sort()
    elif command == 2:
        count = 0
        for i in range(start, end + 1):
            if i not in quests:
                count += 1
        print(count)
        
    
for i in range(m):
    command = list(map(int, input().split()))
    if command[0] == 1:
        commands(command[0], quest, command[1], 0)
    elif command[0] == 2:
        commands(command[0], quest, command[1], command[2])