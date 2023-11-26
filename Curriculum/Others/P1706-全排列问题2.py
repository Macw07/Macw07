n = int(input())
vis = []

def permutation(k, ni):
    global vis
    if k > ni:
        for i in range(n):
            print("    " + str(vis[i]), end='')
        print()
        return
    for i in range(1, ni+1):
        if i in vis:
            continue
        vis.append(i)
        permutation(k+1, ni)
        vis.pop()

permutation(1, n)