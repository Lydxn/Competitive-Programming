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

ll bit1[1000001], bit2[1000001]; int N;
bool sieve[100001];

void update(ll *bit, int a, ll k) { for (; a <= N; a += a & -a) bit[a] += k; }
void update(int a, int b, ll k) {
	update(bit1, a, k), update(bit1, b + 1, -k);
	update(bit2, a, k * (a - 1)), update(bit2, b + 1, -k * b);
}

ll query(ll *bit, int a) { ll res = 0; for (; a; a -= a & -a) res += bit[a]; return res; }
ll query(int a) { return query(bit1, a) * a - query(bit2, a); }
ll query(int a, int b) { return query(b) - query(a - 1); }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, S, a, b, k; ll ans = INFL;
	cin >> N >> T;
	
	sieve[1] = true;
	for (int i = 2; i * i <= T; i++)
		if (!sieve[i])
			for (int j = i * i; j <= T; j += i)
				sieve[j] = true;
	
	for (int i = 1; i <= N; i++) cin >> S, update(i, i, S);
	for (int i = 1; i <= T; i++) {
		cin >> a >> b >> k;
		if (sieve[i]) update(a, b, k);
		else ans = min(ans, (query(a, b) + k) * i);
	}
	cout << ans << '\n';
	return 0;
}
