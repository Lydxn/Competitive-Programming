#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int S[22];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, cnt = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= N; i++) cnt += S[i - 1] < 41 && S[i] < 41 && S[i + 1] < 41;
	cout << cnt << '\n';
	return 0;
}
