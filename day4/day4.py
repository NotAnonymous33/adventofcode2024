from itertools import product

with open("input.txt") as file:
    array = file.readlines()

num_rows = len(array)
num_cols = len(array[0]) - 1 # -1 for \n at end of each line

def check_direction(row, col, dx, dy):
    string = "XMAS"
    for i in range(4):
        if not (0 <= row + i * dy < num_rows and 0 <= col + i * dx < num_cols):
            return False
        if array[row + i * dy][col + i * dx] != string[i]:
            return False
    return True
    

def check_point(row, col):
    d = [0, -1, 1]
    directions = list(product(d, repeat=2))
    directions.remove((0, 0))
    return sum(map(lambda x:check_direction(row, col, *x), directions))
    

count = 0
for row_num in range(num_rows):
    for col_num in range(num_cols):
        count += check_point(row_num, col_num)
print(count)


