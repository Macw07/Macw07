import math  # 引入头文件 - math
h = int(input())  # 读入一个类型为int的数字
r = int(input())  # 读入一个类型为int的数字
# h, r = map(int, input().split())

# 接下来，我们需要计算桶的体积 底面积*高
base = 3.14 * r * r  # \pi * r^2
volume = base * h  # 总体积 (单位：毫升)

need = 20 * 1000

# 总需求 / 体积 => 个数
# 向上取整 ceil
print(math.ceil(need / volume))
