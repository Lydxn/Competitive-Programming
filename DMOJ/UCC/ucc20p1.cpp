#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, cnt = 0; string a, b;
	cin >> N >> a >> b;
	for (int i = 0; i < N; i++) cnt += a[i] == '0' && b[i] == '0';
	cout << cnt << '\n';
	return 0;
}
