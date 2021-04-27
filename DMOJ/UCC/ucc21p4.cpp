#include <bits/stdc++.h>

using namespace std;

int N, f[500001], d[500001];
queue<int> q;

int F(int n) {
	return f[n] + n % 50;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	f[1] = 1, f[2] = 1;
	for (int i = 3; i <= N; i++) f[i] = (f[i - 1] + f[i - 2]) % 2021;
	memset(d, -1, sizeof(d));
	q.push(1); d[1] = 0;
	while (!q.empty()) {
		int i = q.front(); q.pop();
		int x = F(i);
		if (1 <= i + x && i + x <= N && d[i + x] == -1) q.push(i + x), d[i + x] = d[i] + 1;
		if (1 <= i - x && i - x <= N && d[i - x] == -1) q.push(i - x), d[i - x] = d[i] + 1;
		if (1 <= i + 1 && i + 1 <= N && d[i + 1] == -1) q.push(i + 1), d[i + 1] = d[i] + 1;
		if (1 <= i - 1 && i - 1 <= N && d[i - 1] == -1) q.push(i - 1), d[i - 1] = d[i] + 1;
	}
	cout << d[N] << '\n';
	return 0;
}