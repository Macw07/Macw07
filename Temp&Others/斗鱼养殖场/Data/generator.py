# Credit @ Marco Wang
import random

for i in range(1, 21):
	with open(f"testcase{i}.in", "w") as file:
		m = random.randint(2, 100)
		n = random.randint(2, 10)
		file.write(f"{m} {n}\n")
		for row in range(m):
			string = ""
			for column in range(n):
				index = random.randint(1, 10)
				if index <= 3:
					string += "0 "
				else:
					string += "1 "
			file.write(string + "\n")
