import random

for i in range(20, 21):
	with open(f"testcase{i}.in", "w") as file:
		# n = random.randint(1, 1000)
		n = 1000
		m = random.randint(1, n)
		file.write(f"{n} {m}\n")
