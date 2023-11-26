num, r = map(int, input().split())

vis = [0] * 30
ans = [0] * 30
# vis[i] = 1 => 数字i已经被使用过了，不能再用了
# vis[i] = 0 => 数字i没有被使用过

def next_permutation(n: int) -> None:
    global num
    if n > r:
        for i in range(1, r+1):
            print(' ' * (3-len(str(ans[i]))) + str(ans[i]), end='')
        print()
        return
    for i in range(ans[n-1]+1, num+1):
        if vis[i] == 1:
            continue
        vis[i] = 1
        ans[n] = i
        next_permutation(n+1)  # 这一层已经确定好了，要换到下一层去了。
        vis[i] = 0

next_permutation(1)