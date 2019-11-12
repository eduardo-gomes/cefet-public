n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
ns = 0
da = True
for x in range(n):
	if a[x] == b[x]:
		ns += 1
a.sort()
b.sort()
for x in range(n):
	if a[x] != b[x]:
		da = False
#if ns > 2:
#	da = False
if da:
	print("Yes")
else:
	print("No")