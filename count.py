import sys

f = open(sys.argv[1])
lines = f.read()
count = 0
for c in lines:
	if c == "\t":
		count += 1

print(count)
f.close()
