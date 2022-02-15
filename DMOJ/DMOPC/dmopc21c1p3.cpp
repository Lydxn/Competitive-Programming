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

const int MM = 44851;
bool ans[MM];
int N, M, u[MM], v[MM];

void solve(int l, int r) {
	if (l >= r) return;

	int mid = (l + r) >> 1, A = mid - l + 1, B = r - mid;
	cout << "? " << A << ' ' << B << '\n';
	for (int i = l; i <= mid; i++) cout << i << " \n"[i == mid];
	for (int i = mid + 1; i <= r; i++) cout << i << " \n"[i == r];
	cout << flush;

	int R, idx; cin >> R;
	while (R--) cin >> idx, ans[idx] = false;
	solve(l, mid), solve(mid + 1, r);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> u[i] >> v[i];
	memset(ans, true, sizeof(ans));
	solve(1, N);
	cout << "! ";
	for (int i = 1; i <= M; i++) cout << ans[i];
	cout << '\n' << flush;
	return 0;
}
