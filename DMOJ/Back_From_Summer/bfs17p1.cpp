#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, cnt = 0; string S;
	cin >> N;
	while (N--) cin >> S, cnt += int(S.size()) <= 10;
	cout << cnt << '\n';
	return 0;
}
