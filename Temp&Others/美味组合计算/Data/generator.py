import random

for i in range(10, 16):
	arr = []
	with open(f"testcase{i}.in", "w") as file:
		n = 10000
		p = random.randint(1, 15000)
		file.write(f"{n} {p}\n")
		content = ""
		while len(arr) < n:
			num = random.randint(1, 15000)
			if num not in arr:
				arr.append(num)
				content += str(num) + " "
		file.write(content)