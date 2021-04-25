#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[100000], pos[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i], pos[a[i]] = i;

	for (int i = 0; i < N && K; i++) {
		if (a[i] != N - i) {
			swap(a[i], a[pos[N - i]]), swap(pos[a[pos[N - i]]], pos[a[i]]), --K;
		}
	}

	for (int i = 0; i < N; i++) cout << a[i] << ' ';
	cout << '\n';
	return 0;
}
