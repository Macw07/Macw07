
n = int(input())

k = 0

def check(m):
    return (m+1)*m//2 >= k

for i in range(n):
    k = int(input())
    mid = 0
    l = 0
    r = k
    while l <= r:
        mid = (l+r) // 2
        if check(mid):
            r = mid - 1
            ans = mid
        else:
            l = mid + 1
    print(ans)