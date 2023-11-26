a = input()
b = input()

lst = [0, 0, 0]
lst[1] = int(a)
lst[2] = int(b)

flag = False

for i in range(3, 26):
    k = lst[i-1] + lst[i-2]
    lst.append(k)
    # print(lst[i])
    if str(lst[i])[::-1] == str(lst[i-1]):
        flag = True
        print(lst[i])
        break

if flag == False:
    print(-1)
