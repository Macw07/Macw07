import random

for i in range(1, 21):
	with open(f"testcase{i}.in", "w") as file:
		n = 1000
		file.write(str(n) + "\n")
		content = ""
		for j in range(n):
			content += str(random.randint(1, 100000)) + " "
		file.write(content)