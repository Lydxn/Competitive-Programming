from datetime import datetime
import math

F = math.floor
GREGORIAN_EPOCH = 1721425.5

def is_leap(y):
	return y % 4 == 0 and (y % 100 != 0 or y % 400 == 0)

def gregorian_to_jd(y, m, d):
	tm = 0 if m <= 2 else (-1 if is_leap(y) else -2)
	y -= 1
	return GREGORIAN_EPOCH - 1 + 365 * y + F(y / 4) -F (y / 100) + F(y / 400) + F((367 * m - 362) / 12) + tm + d

def jd_to_gregorian(jd):
	wjd = F(jd - 0.5) + 0.5
	depoch = wjd - GREGORIAN_EPOCH
	quadricent = F(depoch / 146097)
	dqc = depoch % 146097
	cent = F(dqc / 36524)
	dcent = dqc % 36524
	quad = F(dcent / 1461)
	dquad = dcent % 1461
	yindex = F(dquad / 365)
	y = quadricent * 400 + cent * 100 + quad * 4 + yindex
	if not (cent == 4 or yindex == 4):
		y += 1

	yearday = wjd - gregorian_to_jd(y, 1, 1)
	leapadj = 0 if wjd < gregorian_to_jd(y, 3, 1) else (1 if is_leap(y) else 2)
	m = F((((yearday + leapadj) * 12) + 373) / 367)
	d = wjd - gregorian_to_jd(y, m, 1) + 1
	return y, m, d

N = int(input())
for _ in range(N):
	units = list(map(int, input().split()))
	days, mul = 0, 1
	for i in range(len(units) - 1, -1, -1):
		days += units[i] * mul
		mul *= 18 if i == len(units) - 2 else 20

	jd = days + 584283
	y, m, d = jd_to_gregorian(jd)
	if y < 0:
		print('%05d-%02d-%02d' % (y, m, d))
	else:
		print('%04d-%02d-%02d' % (y, m, d))