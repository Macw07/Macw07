import random
n = int(input())
nameList = ["Camel", "Dami", "Cindy", "Marco", "Selina",
            "Pluto", "Quanzi", "Wenly", "Will", "Vernon",
            "Cooper", "Robinson", "Washington", "Carber", "Edwardz",
            "Sunny", "Jason", "Paul", "Tom", "Vincent",
            "Andromeda", "Libby", "Alice", "Ted", "Dorina",
            "Redwood", "Jack", "Terry", "Jackie", "Nody"]
MaleData = []
FemaleData = []

while True:
    a = random.randint(1000, 2000)
    if a not in MaleData:
        MaleData.append(a)
    if len(MaleData) == 30:
        break

while True:
    a = random.randint(1000, 2000)
    if a not in MaleData and a not in FemaleData:
        FemaleData.append(a)
    if len(FemaleData) == 30:
        break

for i in range(n):
    a = random.randint(0, 29)
    h = random.randint(0, 24)
    m = random.randint(0, 60)
    g = random.randint(0, 1)
    if g == 1:
        print(nameList[a], MaleData[a], "Male", str(h) + ":" + str(m))
    else:
        print(nameList[a], FemaleData[a], "Female", str(h) + ":" + str(m))
