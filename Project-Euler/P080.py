s = 0
for R in range(1, 101):
	if R in [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]:
		continue
		
	v = 1
	for x in range(2021):
		v = (v + R * 10**200 // v) // 2
	v = str(v)
	s += sum(int(v[i]) for i in range(100))
print(s)