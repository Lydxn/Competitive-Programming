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

int N, K, A[20000];
ll P[20001], hsh[20001];
unordered_map<ll, int> cnt;

bool f(int x) {
	cnt.clear();
	for (int i = 0; i < N - x + 1; i++)
		++cnt[((hsh[i] - hsh[i + x] * P[x]) % MOD + MOD) % MOD];

	for (auto i : cnt)
		if (i.second >= K) return true;
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];

	P[0] = 1;
	for (int i = 1; i <= N; i++) P[i] = P[i - 1] * 31 % MOD;
	for (int i = N - 1; i >= 0; i--) hsh[i] = (hsh[i + 1] * 31 + A[i]) % MOD;

	int l = 0, r = N, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (f(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l - 1 << '\n';
	return 0;
}
