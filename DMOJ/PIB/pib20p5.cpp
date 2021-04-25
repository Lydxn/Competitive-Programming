#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[1000][1000], tmp[1000], k[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 1; j < N; j++)
			cin >> a[i][j], a[i][j] += a[i][j - 1];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) tmp[j] = a[j][i];
		sort(tmp, tmp + N);
		k[i] = tmp[(N - 1) / 2];
	}

	sort(k, k + N);
	cout << "YES\n";
	for (int i = 0; i < N; i++) cout << -k[(N - 1) / 2] << ' ';
	cout << '\n';
	return 0;
}
