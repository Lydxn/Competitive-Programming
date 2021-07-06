#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0, csc = 0; string S, prev = " ";
	cin >> N;
	while (N--) {
		cin >> S;
		if (prev[0] == S[0]) ans = (ans + ++csc) % 1000000007;
		else csc = 1, ++ans;
		prev = S;
	}
	cout << ans << '\n';
	return 0;
}
