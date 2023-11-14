f = open("transistor-counts.csv", "r")
lines = f.readlines()
for line in lines:
    line = line.split(',')
    if line[0] == "#processor":
        continue
    line[0] = str(line[0].strip())
    line[1] = int(line[1].strip())
    line[2] = int(line[2].strip())
    print(line[0], line[1], line[2])