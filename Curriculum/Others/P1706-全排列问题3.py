n = int(input())

"""
vis2 = [0, 0, 0, 0]
for i in range(1, 3+1):
    vis2[i] = 1
    for j in range(1, 3+1):
        if vis2[j] == 1:
            continue
        vis2[j] = 1
        for k in range(1, 3+1):
            if vis2[k] == 1:
                continue
            vis2[k] = 1
            print(i, j, k)
            vis2[k] = 0
        vis2[j] = 0
    vis2[i] = 0
"""
# vis[i] = 1 -> 这个数已经用过了，不能再用了
# vis[i] = 0 -> 这个数没有被用过，可以使用
vis = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# arr 表示答案 -> arr[i] 表示的是答案的第i位
arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

"""
depth -> 递归的深度
    实际含义：表示已经确定了depth个位数
"""
def permutation(depth):
    global n, vis, arr
    if depth > n:
        for i in range(1, n+1):
            print("    " + str(arr[i]), end="")
        print()
        return
    for i in range(1, n+1):
        # 这个数不可以跟之前用过的数相同：1 2 2 是不合法的，需要过滤掉
        if vis[i] == 1:
            continue
        vis[i] = 1
        arr[depth] = i
        # 继续去确定下一位
        permutation(depth+1)
        vis[i] = 0

permutation(1)