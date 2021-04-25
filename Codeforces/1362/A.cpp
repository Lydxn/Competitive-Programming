#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pair<int, ll> twos(ll n) {
	int res = 0;
	while ((n & 1) == 0) n >>= 1, ++res;
	return {res, n};
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; ll a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		pair<int, ll> ta = twos(a), tb = twos(b);
		cout << (ta.second != tb.second ? -1 : (abs(ta.first - tb.first) + 2) / 3) << '\n';
	}
	return 0;
}
