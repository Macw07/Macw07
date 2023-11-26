a = int(input())
b = a
count = 1
while True:
    a = a * 3 + 1
    a %= 100
    count += 1
    if a == b:
        print(count)
        break
