import random
length = int(input())
origin = []
result = []
for i in range(length):
    num = str(random.randint(0, 9))
    origin.append(num)
    result.append(num)
random.shuffle(result)

for i in range(random.randint(1, length)):
    rd = random.randint(1, length-1)
    result[rd] = '#'

for i in range(length):
    print(origin[i], end="")
print()
for i in range(length):
    print(result[i], end="")
