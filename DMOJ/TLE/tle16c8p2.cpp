#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		string ans = "";
		do ans = (N & 1 ? "dank " : "meme ") + ans, N >>= 1;
		while (N);
		cout << ans << '\n';
	}
	return 0;
}
