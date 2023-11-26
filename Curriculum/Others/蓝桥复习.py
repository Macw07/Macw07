# A + B Problem
"""
a, b, c = map(int, input().split())

for i in range(a, b+1):
    for j in range(i, b+1):
        if j % i == c:
            print(i, j)
"""

# Calender
"""
month, year = map(int, input().strip().split(', '))
months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def isLeapYear(crt_year):
    return crt_year % 4 == 0 and (crt_year % 100 != 0 or crt_year % 400 == 0)

if isLeapYear(year):
    months[2] += 1

print(months[month])
"""

# Monumental Day
"""
2023 2
4 18
5 12
3
5 10
5 13
4 15
"""
"""
year, days = map(int, input().split())
arr = []
months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def isLeapYear(crt_year):
    return crt_year % 4 == 0 and (crt_year % 100 != 0 or crt_year % 400 == 0)

if isLeapYear(year):
    months[2] += 1

for i in range(0, days):
    month, day = map(int, input().split())
    arr.append(month + day / 100)
arr.sort()

times = int(input())
for i in range(0, times):
    month, day = map(int, input().split())
    current_day = month + day / 100
    flag = 0
    for j in range(0, days):
        if current_day < arr[j]:
            calculate = 0
            flag = 1
            # 模拟日期的递增
            while True:
                if day == months[month]:
                    month = month + 1
                    day = 1
                day += 1
                calculate += 1
                if month + day / 100 == arr[j]:
                    print(calculate)
                    break
            break
    if flag == 0:
        print(-1)
"""

# Score Ranking
"""
95
10
99 95 90 99 80 70 71 78 77 60
"""
"""
ming_sore = int(input())
n = int(input())
lst = list(map(int, input().split()))
lst.sort(reverse=True)
rank = lst.index(ming_sore) + 1
if rank/n <= 0.1:
    print("A")
elif rank/n <= 0.3:
    print("B")
elif rank/n <= 0.6:
    print("C")
elif rank/n <= 0.8:
    print("D")
else:
    print("E")
"""
