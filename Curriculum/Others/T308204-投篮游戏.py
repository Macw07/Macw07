n: int = int(input())
arr = list(map(int, input().split()))
ans = 0

# 创建dp数组
# dp[i]表示的是：当n的长度为i的时候的最长下降子集合
dp = []

for i in range(0, n):
    dp.append(1)
    for j in range(0, i):
        if arr[i] < arr[j]:
            dp[i] = max(dp[j] + 1, dp[i])
    ans = max(dp[i], ans)

print(ans)