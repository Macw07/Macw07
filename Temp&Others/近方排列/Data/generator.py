import random

for i in range(11, 16):
	arr = []
	print(i)
	with open(f"testcase{i}.in", "w") as file:
		n = 100000
		file.write(f"{n}\n")
		content = ""
		while len(arr) < n:
			num = random.randint(1, 150000)
			arr.append(num)
			content += str(num) + " "
		file.write(content)