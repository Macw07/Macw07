t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    h = list(map(int, input().split()))
    l = list(map(int, input().split()))
    arr = []
    prefix = []
    for i in range(max(h)):
        arr.append(0)
        for j in range(n):
            if l[j] <= i < h[j]:
                arr[i] += 1
	# arr[i]第i个区间里有arr[i]根香肠。
    flag = 1
    for i in range(1, len(arr)):
        if arr[i] > k:
            continue
        if arr[i] == k:
            print(i, i+1)
            flag = 0
            break
        left = i
        right = len(arr)-1
        vis = [0 for _ in range(len(arr)+2)]
        while left <= right and flag and right <= len(arr)-1:
            mid = (left + right) >> 1
            if vis[mid]:
                break
            vis[mid] = 1
            now = sum(arr[i:mid])
            if now == k:
                print(i, mid)
                flag = 0
                break
            elif now > k:
                right = mid - 1
            else:
                right = mid + 1
    if flag:
        print("IMPOSSIBLE")