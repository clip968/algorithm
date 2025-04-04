data = input()
row = int(data[1])
column = int(ord(data[0])) - int(ord('a')) + 1

steps = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (2, 1), (1, 2), (2, -1), (1, -2)]

result = 0
for step in steps:
    move_row = row + step[0]
    move_column = column + step[1]
    
    if move_column <= 8 and move_row <= 8 and move_column >= 1 and move_row >= 1:
        result += 1
        
print(result)