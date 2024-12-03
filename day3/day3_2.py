import re

def multiply(s: str):
    s = s.strip("mul()").split(",")
    return int(s[0]) * int(s[1])
    
with open("input.txt") as file:
    text = "".join(file.readlines())

valid_strings = re.findall("mul\([0-9]+,[0-9]+\)|do\(\)|don't\(\)", text)

ans = 0
enabled = True
for s in valid_strings:
    if s[0] == "m" and enabled:
        ans += multiply(s)
    elif s == "do()":
        enabled = True
    else:
        enabled = False
print(ans)
    
    
