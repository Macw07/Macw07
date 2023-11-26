# https://oucc.seedasdan.org/index.php?action=user_question&grq_id=1769
# 111000100100010101111000011101

board = [[-1 for i in range(10)] for j in range(10)]
visited = [[0 for i in range(10)] for j in range(10)]

flag = 0
dx = [0, 1]
dy = [1, 0]
max_red = 0
max_yellow = 0

def dfs(x: int, y: int, color: int, length: int, direction: int) -> None:
    # print(x, y, length)
    global board, visited, dx, dy, max_red, max_yellow, flag
    if length == 3:
        flag = 1
        return
    new_x = x + dx[direction]
    new_y = y + dy[direction]
    if new_x < 0 or new_y < 0 or new_x >= 5 or new_y >= 6 or visited[new_x][new_y] == 1 or board[new_x][new_y] != color:
        pass
    else:
        dfs(new_x, new_y, color, length + 1, direction)
    return



string = input()
for i in range(0, 5):
    for j in range(0, 6):
        board[i][j] = int(string[6*i+j])

# print(board)

for i in range(0, 5):
    for j in range(0, 6):
        for k in range(0, 2):
            flag = 0
            dfs(i, j, board[i][j], 1, k)
            if flag:
                if board[i][j] == 1:
                    max_red += 1
                else:
                    max_yellow += 1

print('R', max_red)
print('Y', max_yellow)

if max_yellow == max_red:
    print("tie")
elif max_red > max_yellow:
    print('R')
else:
    print('Y')
