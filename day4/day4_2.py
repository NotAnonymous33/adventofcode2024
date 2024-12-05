from itertools import product

with open("input.txt") as file:
    array = file.readlines()

num_rows = len(array)
num_cols = len(array[0]) - 1 # -1 for \n at end of each line

def check_point(row, col):
    if array[row][col] != "A":
        return False
    diag1 = set([array[row-1][col-1], array[row+1][col+1]])
    diag2 = set([array[row-1][col+1], array[row+1][col-1]])
    return diag1 == diag2 == set("MS")
    

count = 0
for row_num in range(1, num_rows - 1):
    for col_num in range(1, num_cols - 1):
        count += check_point(row_num, col_num)
print(count)


