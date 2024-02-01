# Credit @ Marco Wang
import random

i = 28
with open(f"Data/testcase{i}.in", "w") as file:
	m = 5
	n = 5
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
