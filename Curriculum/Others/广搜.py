import queue

n, m = map(int, input().strip().split())
arr = [[] for _ in range(n+2)]
vis = [[0 for _ in range(m+2)] for _ in range(n+2)]

"""
3 5
* * * * *
* * # # *
* * # * *
"""

for i in range(1, n+1):
    k = list(input().strip().split())
    arr[i].append(0)
    arr[i].extend(k)

que = queue.Queue()
que.put((1, 1, 0))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

while not que.empty():
    head = que.get()
    if head[0] == n and head[1] == m:
        print(head[2])
        break
    for i in range(4):
        next_x = head[0] + dx[i]
        next_y = head[1] + dy[i]
        if next_x < 1 or next_y < 1:
            continue
        if next_x > n or next_y > m:
            continue
        if arr[next_x][next_y] == '#' or vis[next_x][next_y] == 1:
            continue
        # print(next_x, next_y, head[2])
        vis[next_x][next_y] = 1
        new_tuple = (next_x, next_y, head[2] + 1)
        que.put(new_tuple)

