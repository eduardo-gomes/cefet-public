s = input()
sz = len(s)
a = ""
for x in range(sz):
	if x%2 == 0:
		a += s[x]
print(a)