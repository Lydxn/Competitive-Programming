import sys
raw_input = sys.stdin.readline

N, M = map(int, raw_input().split(' '))
INF = 1 << 99
D = [[INF for i in range(N + 1)] for i in range(N + 1)]
for i in range(1, N + 1):
	D[i][i] = 0
for i in range(M):
	a, b, w = map(int, raw_input().split(' '))
	D[a][b] = w
for i in range(1, N + 1):
	for j in range(1, N + 1):
		for k in range(1, N + 1):
			D[i][j] = min(D[i][j], D[i][k] + D[k][j])
Q = int(raw_input())
for i in range(Q):
	a, b = map(int, raw_input().split(' '))
	ans = D[a][b]
	print -1 if ans == INF else ans % 1000000007