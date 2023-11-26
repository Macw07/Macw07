import random

for i in range(16, 31):
	str1 = "Q" + str(i) + ".in"
	file = open(str1, 'w')
	T = 100
	file.write(str(T) + '\n')

	for num in range(0, T):
		L = random.randint(1, 5000)
		N = min(L, random.randint(1, 5000))
		M = min(L, random.randint(1, 5000))
		K = min(L, random.randint(1, 50))

		arr1 = []
		arr2 = []

		for i in range(0, N):
			k = random.randint(1, N)
			arr1.append(k)

		for i in range(0, M):
			k = random.randint(1, M)
			arr2.append(k)

		arr1 = set(arr1)
		arr2 = set(arr2)
		len1 = len(arr1)
		len2 = len(arr2)
		file.write(str(L) + ' ' + str(len1) + ' ' + str(len2) + ' ' + str(K) + '\n')

		for i in arr1:
			file.write(str(i) + ' ')
		file.write('\n')

		for i in arr2:
			file.write(str(i) + ' ')
		file.write('\n')
