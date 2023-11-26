# 常量时间复杂度
a = 10
b = 20
print(a + b)
print(a - b)
print(a * b)
print(a / b)
# T = O(1)

# 线性时间复杂度
n = int(input())
for i in range(n):
    print(i)
# T = O(n)

# O(n^2)时间复杂度
for i in range(n*n):
    print(i)

for i in range(n):
    for j in range(n):
        print(i)

# O(n!)时间复杂度
# 在进行全排列等排列组合的情况下，时间复杂度通常为O(n!)

# O(2^n)时间复杂度
# 一般会出现在二叉树等递归结构中

# O(log2 n)时间复杂度


