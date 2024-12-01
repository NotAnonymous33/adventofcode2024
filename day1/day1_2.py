from collections import Counter

with open("day1input.txt") as f:
    lines = f.readlines()

lines = [line.split() for line in lines]
list1, list2 = zip(*lines)

list1 = list(map(int, list1))
counter = Counter(list(map(int, list2)))

ans = 0

for i in list1:
    ans += counter[i] * i

print(ans)






    

    
