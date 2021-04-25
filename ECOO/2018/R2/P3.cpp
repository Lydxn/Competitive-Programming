#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

vector<pii> pf;
int K, M;

bool f(ll x) {
	for (pii p : pf) {
		ll cnt = 0;
		for (ll i = p.first; i <= x; i *= p.first) cnt += x / i;
		if (cnt < (ll) p.second * M) return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 10; _++) {
		cin >> K >> M;

		pf.clear();
		for (int i = 2; i <= K; i++) {
			int cnt = 0;
			while (K % i == 0) K /= i, ++cnt;
			if (cnt) pf.emplace_back(i, cnt);
		}

		ll l = 0, r = LLONG_MAX, m;
		while (l < r) {
			m = (l + r) / 2;
			if (f(m)) r = m;
			else l = m + 1;
		}
		cout << l << '\n';
	}
	return 0;
}
