import numpy as np

with open("day1input.txt") as f:
    lines = f.readlines()

lines = [line.split() for line in lines]
list1, list2 = zip(*lines)

list1 = np.array(list(map(int, list1)))
list2 = np.array(list(map(int, list2)))

list1 = np.sort(list1, axis=0)
list2 = np.sort(list2, axis=0)

differences = np.array(list1) - np.array(list2)
print(sum(abs(differences)))




    

    
