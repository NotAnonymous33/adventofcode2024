def is_safe(nums: list[int]) -> bool:
    if nums[0] > nums[1]:
        direction = -1
    else:
        direction = 1
    
    for i in range(len(nums) - 1):
        if direction * (nums[i + 1] - nums[i]) <= 0:
            return False
        diff = abs(nums[i+1] - nums[i])
        if diff > 3 or diff < 1:
            return False
        
    return True

with open('input.txt') as f:
    lines = f.readlines()
    lines = list(map(lambda x: list(map(int, x.split())), lines))

count = 0
for line in lines:
    if is_safe(line):
        count += 1
    else:
        for i in range(len(line)):
            new_line = line[:]
            new_line.pop(i)
            if is_safe(new_line):
                count += 1
                break

print(count)