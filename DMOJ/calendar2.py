from datetime import datetime

def gregorian(y, m, d):
	if m in (1, 2):
		y -= 1

	K, J = y % 100, y // 100
	m = (m - 3) % 12 + 3
	return (d + 13 * (m + 1) // 5 + K + K // 4 + J // 4 - 2 * J) % 7

def julian(y, m, d):
	if m in (1, 2):
		y -= 1

	K, J = y % 100, y // 100
	m = (m - 3) % 12 + 3
	return (d + 13 * (m + 1) // 5 + K + K // 4 + 5 - J) % 7

WEEKDAYS = ['Saturday', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']

N = int(input())
for _ in range(N):
	y, m, d = map(int, input().rsplit('-', 2))
	if y > 1752 or (y == 1752 and m > 9) or (y == 1752 and m == 9 and d >= 14):
		print(WEEKDAYS[gregorian(y, m, d)])
	else:
		print(WEEKDAYS[julian(y, m, d)])