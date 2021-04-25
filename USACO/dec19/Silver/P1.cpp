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

int m[] = {1, 2, 4, 7, 8, 11, 13, 14};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);

	int N;
	cin >> N;
	cout << 1LL * (N - 1) / 8 * 15 + m[(N - 1) % 8] << '\n';
	return 0;
}
