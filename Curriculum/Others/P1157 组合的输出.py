n, r = map(int, input().split())

"""
排列和组合的区别是什么？

排列是相同的数变换位置
1 2 3 是一种排列
1 3 2 是另一种排列

组合是不同的数组成的不同的单调列表
1 2 3 是一种组合
1 3 2 和上面是同一种组合
"""

vis = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

def permutation(depth):
    global n, r, vis, arr
    if depth > r:
        for i in range(1, r+1):
            if len(str(arr[i])) == 1:
                print("  " + str(arr[i]), end="")
            else:
                print(" " + str(arr[i]), end="")
        print()
        return

    for i in range(arr[depth-1] + 1, n+1):
        arr[depth] = i
        permutation(depth+1)

permutation(1)