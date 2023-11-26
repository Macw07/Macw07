# 创建一个变量，int类型，名为n
n: int = int(input())
lst = []

# 当n不为1的时候，就一直根据题干进行循环
while n != 1:
    # 保存路径
    lst.append(n)
    if n % 2 == 1:
        n = n * 3 + 1
    else:
        n = n // 2
# 题干中1也是在路径中的
lst.append(1)

# 倒序输出路径
for i in range(len(lst)-1, -1, -1):
    print(lst[i], end=' ')