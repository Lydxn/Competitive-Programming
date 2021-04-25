#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool stop[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, R, M, S, cnt = 0;
	cin >> N >> R >> M;
	for (int i = 0; i < R; i++) cin >> S, stop[S] = true;
	for (int i = 0; i < M && cnt < M / 2; i++) cin >> S, cnt += stop[S];
	cout << cnt * (cnt + 1) / 2 + (M - cnt) * (M - cnt + 1) / 2 << '\n';
	return 0;
}
