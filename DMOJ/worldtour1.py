N = int(input())
for i in range(N):
	s = input()
	if s[0].lower() == 'b':
		print('m' + s)
	elif s[0].lower() == 'c':
		print('g' + s)
	elif s[0].lower() == 'd':
		print('n' + s)
	elif s[0].lower() == 'f':
		print('bh' + s)
	elif s[0].lower() == 'g':
		print('n' + s)
	elif s[0].lower() == 'p':
		print('b' + s)
	elif s[0].lower() == 't':
		print('d' + s)
	elif s[0] in 'aeiouáéíóú':
		print('n-' + s)
	elif s[0] in 'AEIOUÁÉÍÓÚ':
		print('n' + s)
	else:
		print(s)