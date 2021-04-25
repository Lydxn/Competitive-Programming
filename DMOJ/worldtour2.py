def f(x):
	if x % 10 in [0, 5, 6, 7, 8, 9] or 10 <= x % 100 <= 19:
		return 'кочерёг'
	elif x % 10 == 1:
		return 'кочерга'
	elif x % 10 in [2, 3, 4]:
		return 'кочерги'

x = int(input())

if f(x) != 'кочерёг':
	print('%d %s' % (x, f(x)))
else:
	a = x
	while True:
		a -= 1
		if f(a) != 'кочерёг':
			break
	b = x - a
	print('%d %s и ещё %s' % (a, f(a), b))