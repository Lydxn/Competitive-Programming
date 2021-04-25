#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int B;
	cin >> B;
	int ans = 5 * B - 400;
	cout << ans << '\n';
	cout << (ans < 100 ? 1 : ans > 100 ? -1 : 0) << '\n';
	return 0;
}