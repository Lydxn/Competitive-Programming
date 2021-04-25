#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, v, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v, cnt += v > 0;
	cout << cnt << '\n';
	return 0;
}
