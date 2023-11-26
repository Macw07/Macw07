'''
encode
meetbillybeaverat6
'''
import math
ed_type = input()
text = input()
table = [['X' for _ in range(5)] for _ in range(15)]

if ed_type == "encode":
    for i in range(0, len(text)):
        column = i % 4
        row = i // 4
        table[row][column] = text[i]

    for i in range(0, 4):
        for j in range(0, math.ceil(len(text)/4)):
            print(table[j][i].upper(), end="")

else:
    cnt = 0
    for i in range(0, 4):
        for j in range(0, math.ceil(len(text)/4)):
            table[j][i] = text[cnt]
            cnt += 1

    for i in range(0, len(text)):
        column = i % 4
        row = i // 4
        print(table[row][column].lower(), end="")