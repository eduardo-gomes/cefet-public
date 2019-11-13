qnt = int(input())
a = input()
b = input()
eq = 0
for x in range(qnt):
	eq += a[x] == b[x]
print(eq)