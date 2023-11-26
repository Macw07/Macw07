import math
# a = int(input())
# b = int(input())
# c = int(input())
a, b, c = map(float, input().split())

p = (a + b + c) * 0.5
area = math.sqrt(p * ((p - a) * (p - b) * (p - c)))
# 保留小数 round
print(round(area, 1))
