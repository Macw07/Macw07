n, k = map(int, input().split())
numList = list(map(int, input().split()))
total = 0
def isPrime(mid):
    if mid < 2:
        return False
    if mid == 2:
        return True
    for i in range(2, int(mid ** 0.5) + 1):
        if mid % i == 0:
            return False
    return True

"""
depth -> 递归的深度，表示已经选了depth个数字。
sum -> 当深度位depth时，当前状态下选择的所有的数字的总和。
next_index -> 这个数选了，之后就从这个数之后的数开始选，就不选前面的数字了。
"""
def permutation(depth, sum, next_index):
    global n, k, total, numList
    if depth > k:
        # print(sum)
        if isPrime(sum):
            total += 1
        return
    for i in range(next_index, n):
        # 为什么不需要 vis 数组？
        """因为这个数将来并不会再次纳入选项之中，所以我们不需要创建vis数组来去重。"""
        permutation(depth+1, sum + numList[i], i + 1)


permutation(1, 0, 0)

print(total)