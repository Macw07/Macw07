origin = []
base = []
vertices = []
mappy = []
H = 0
W = 0
D = 0

def dfs(x, y, steps):
	global base, origin, vertices
	global H, W, D, mappy
	if steps == D:
		return
	mappy[x+1][y+1] = '\\'
	dfs(x+1, y+1, steps+1)

def main():
	global base, origin, vertices
	global H, W, D, mappy
	T = int(input().strip())
	for _ in range(T):
		vertices = []
		base = []
		mappy = [[' ' for _ in range(3010)] for _ in range(3010)]
		s = input()
		H, W, D = map(int, s.strip().split())
		base = [list(input()) for _ in range(H)]
		vertices = []
		for i in range(H):
			for j in range(W):
				if base[i][j] == '+':
					vertices.append([i, j])
				mappy[i][j] = base[i][j]

		for i in vertices:
			dfs(i[0], i[1], 0)

		for i in range(H):
			for j in range(W):
				if base[i][j] == ' ':
					continue
				mappy[i+D+1][j+D+1] = base[i][j]

		for i in range(H+D+1):
			for j in range(W+D+1):
				print(mappy[i][j], end='')
			print()

if __name__ == '__main__':
    main()