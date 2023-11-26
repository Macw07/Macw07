import random
diff = int(input())
n = random.randint(diff//10, diff*10)
m = random.randint(diff//10, diff*10)
k = random.randint(diff//10, 100)
print(n, m, k)
coordinate = []
while len(coordinate) < k:
    x = random.randint(1, n)
    y = random.randint(1, m)
    d = random.randint(0, 3)
    if x == 1 and y == 1:
        continue
    if x == n and y == m:
        continue
    temp = [x, y]
    if temp not in coordinate:
        coordinate.append(temp)
        print(x, y, d)


