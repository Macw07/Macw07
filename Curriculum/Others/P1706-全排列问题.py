# 模拟一下三个数字的全排列
# 递归的三部曲：
"""
1. 确定函数的返回值：只需要输出，不需要返回值
2. 递归的Base Case:
    (确定了几个位置，全排列的n为多少，就是确定了几个位置)
    当所有位置都确定好以后，输出答案，并且return。
3. 递归的每一层循环的内容
    for num in range(1, n+1):
        if num in vis:
            continue
        vis.append(num)
        dfs(具体内容再说)
        vis.pop()
"""

num = int(input())
vis = [0] * 20
ans = [0] * 20
# vis[i] = 1 => 数字i已经被使用过了，不能再用了
# vis[i] = 0 => 数字i没有被使用过

def next_permutation(n: int) -> None:
    global num
    if n > num:
        for i in range(1, num+1):
            print("    " + str(ans[i]), end='')
        print()
        return
    for i in range(1, num+1):
        if vis[i] == 1:
            continue
        vis[i] = 1
        ans[n] = i
        next_permutation(n+1)  # 这一层已经确定好了，要换到下一层去了。
        vis[i] = 0

next_permutation(1)