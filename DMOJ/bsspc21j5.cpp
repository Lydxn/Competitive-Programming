#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

const int MX = 250000;
vector<int> p;
vector<ll> psa;
bool b[MX + 1];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i * i <= MX; i++)
		if (!b[i])
			for (int j = i * i; j <= MX; j += i)
				b[j] = true;
	p.push_back(0);
	for (int i = 2; i <= MX; i++)
		if (!b[i]) p.push_back(i);
	psa.push_back(0);
	for (int i = 1; i < int(p.size()); i++)
		psa.push_back(psa[i - 1] + p[i]);

	int Q, x, k;
	cin >> Q;
	while (Q--) {
		cin >> x >> k;
		int idx = lower_bound(p.begin(), p.end(), x) - p.begin();
		cout << p[idx + k - 1] << ' ' << psa[idx + k - 1] - psa[idx - 1] << '\n';
	}
	return 0;
}