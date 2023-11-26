t, m = map(int, input().split())
times = [0]
values = [0]
dp = [[0 for i in range(1005)] for j in range(1005)]
for i in range(1, m+1):
    ti, vi = map(int, input().split())
    times.append(ti)
    values.append(vi)

for i in range(1, m+1):
    for j in range(0, t+1):
        # 如果装不下？
        if j < times[i]:
            continue
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-times[i]]+values[i])

print(dp[m][t])