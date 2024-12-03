import re

def multiply(s: str):
    s = s.strip("mul()").split(",")
    return int(s[0]) * int(s[1])
    
with open("input.txt") as file:
    text = "".join(file.readlines())

valid_strings = re.findall("mul\([0-9]+,[0-9]+\)", text)
print(sum(map(multiply, valid_strings)))
