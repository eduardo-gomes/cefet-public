a = [100, 101, 102, 103, 104, 105]
s = set()
for x1 in range(1000):
	for x2 in range(1000):
		for x6 in range(1000):
			for x3 in range(1000):
				for x4 in range(1000):
					for x5 in range(1000):
						aa = x1 * a[0] + x2 * a[1] + x3 * a[2] + x4 * a[3] + x5 * a[4] + x6 * a[5]
						print(aa)
						s.add(aa)
