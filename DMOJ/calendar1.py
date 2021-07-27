c1 = '甲乙丙丁戊己庚辛壬癸'
c2 = '子丑寅卯辰巳午未申酉戌亥'

N = int(input())
for _ in range(N):
	y = int(input())
	print(c1[(y - 4) % 10] + c2[(y - 4) % 12])