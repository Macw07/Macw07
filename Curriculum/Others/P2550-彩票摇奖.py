# n: int = int(input())
# awards = list(map(int, input().split()))
# lst = []
#
# # 有可能没中奖，小明的运气是真的背
#
# # lst[i]: 表示的是第i组彩票
# # lst[i][j]: 表示第i组彩票的第j张
#
# for i in range(n):
#     lst.append(list(map(int, input().split())))
#
# ans = [0, 0, 0, 0, 0, 0, 0]
# # 一张一张去遍历，看看有几个是符合的
#
# for i in range(n):
#     sum: int = 0
#     for j in range(0, 7):
#         if lst[i][j] in awards:
#             sum += 1
#     if sum:
#         ans[7-sum] += 1
#
# for i in range(0, 7):
#     print(ans[i], end=' ')
#

n = int(input())
ls = []
ls1 = [0, 0, 0, 0, 0, 0, 0]

for i in range(n + 1):
    a = list(map(int, input().split()))
    ls.append(a)

for x in range(1, n + 1):
    c = list(set(ls[0]) & set(ls[x]))
    if len(c) != 0:
        ls1[len(c) - 1] += 1

ls1.reverse()
for i in ls1:
    print(i, end=" ")
