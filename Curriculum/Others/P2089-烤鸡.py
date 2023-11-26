import copy

n = int(input())
total = []
ans = [0] * 11

# depth为第n个食材
def recursion(depth, current):
    global ans, total, n
    if depth > 10:
        if current == n:
            temp = copy.deepcopy(ans)
            total.append(temp)
        return
    for i in range(1, 4):
        ans[depth] = i
        recursion(depth+1, current + i)

recursion(1, 0)

print(len(total))
for i in range(0, len(total)):
    for j in range(1, 11):
        print(total[i][j], end=' ')
    print()