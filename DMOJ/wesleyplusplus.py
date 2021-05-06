import sys
input = sys.stdin.readline

def f(N):
	assert N % 3 != 0
	L = N.bit_length() - 1
	if N % 3 == 1:
		return 1 << (L - (L & 1))
	else:
		return 1 << (L - (L & 1 == 0))

def p(N):
	print(N)
	sys.stdout.flush()

N = int(input())
if N % 3:
	p(1)
	x = f(N)
	p(x)
	N -= x
else:
	p(2)

while N:
	N -= int(input())
	x = f(N)
	p(x)
	N -= x