n = int(input())
price = [0]
petrol = [0]
for i in range(n):
    a, b = map(int, input().split())
    price.append(a)
    petrol.append(b)

total = 0
best = 0x7f7f7f7f
for i in range(1, n+1):
    if best > price[i]:
        best = price[i]
    total += best
    best += petrol[i]

print(total)

# total = price[1]
# for i in range(2, n+1):
#     ans = 0x7f7f7f7f
#     for j in range(1, i+1):
#         temp = price[j]
#         for k in range(j, i):
#             temp += petrol[k]
#         ans = min(ans, temp)
#     total += ans

# print(total)