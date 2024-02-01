# Credit @ Marco Wang
import random

i = 25
with open(f"Data/testcase{i}.in", "w") as file:
	m = 100
	n = 10
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
