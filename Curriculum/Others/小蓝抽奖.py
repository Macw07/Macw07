n, m = map(int, input().split())
arr = []
vis = [[0] * 105] * 105
ans = 0
dx = [1, 1]
dy = [1, -1]

def check(begin_x, begin_y, end_x, end_y):
    global arr, n, m
    total = 0
    for i in range(min(begin_x, end_x), max(begin_x, end_x)):
        for j in range(min(begin_y, end_y), max(begin_y, end_y)):
            total += arr[i][j]
    return total == abs(end_x - begin_x)

def dfs(begin_x, begin_y, end_x, end_y, len):
    global n, m, arr, ans
    if check(begin_x, begin_y, end_x, end_y):
        ans = max(ans, len)
        vis[end_x][end_y] = 1
        for i in range(0, 2):
            new_x = end_x + dx[i]
            new_y = end_y + dy[i]
            # print(new_x, new_y)
            if new_x < 0 or new_x >= n or new_y < 0 or new_y >= m:
                continue
            if arr[new_x][new_y] == 0:
                continue
            dfs(begin_x, begin_y, new_x, new_y, len+1)


for i in range(n):
    temp = list(map(int, input().split()))
    arr.append(temp)

for i in range(0, n):
    for j in range(0, m):
        if arr[i][j] == 0 or vis[i][j] == 1:
            continue
        dfs(i, j, i, j, 1)

print(ans)