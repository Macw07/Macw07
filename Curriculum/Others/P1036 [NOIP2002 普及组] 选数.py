import math
n, m = map(int, input().split())
# C^n_m

vis = []
arr = list(map(int, input().strip().split()))
total = 0

def isPrime(num):
    if num < 2:
        return False
    if num == 2:
        return True
    for i in range(2, int(math.sqrt(num))+1):
        if num % i == 0:
            return False
    return True


def permutation(idx, sum, startindex):
    global total
    if idx == m:
        # 我们已经取了m个数，可以输出结果
        # print(sum)
        if isPrime(sum):
            total += 1
        return 0

    for i in range(startindex, n):
        number = arr[i]
        permutation(idx + 1, sum + number, i + 1)

permutation(0, 0, 0)
print(total)