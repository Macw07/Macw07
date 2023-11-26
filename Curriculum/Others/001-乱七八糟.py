lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# lst的最后一位 = len(lst)-1
# print(lst[len(lst)-1]) -> 9
# print(lst[0]) -> 1

len(lst)-1, len(lst)-2, ... , 1, 0
for i in range(len(lst)-1, 0, -1):
    # 9 8 7 6 5 4 3 2 1 (0)
    # 因为0没有被取到
    # 所以我们需要多减去一个1
    print(i)

print()

for i in range(len(lst)-1, -1, -1):
    # 9 8 7 6 5 4 3 2 1 (0)
    # 因为0没有被取到
    # 所以我们需要多减去一个1
    print(i)