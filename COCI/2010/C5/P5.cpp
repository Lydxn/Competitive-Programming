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

int A[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i], A[i] += A[i - 1];
	for (int i = 1, j = 1; i <= N; i++) {
		while (j + j - i + 3 <= N && A[j + 1] - A[i - 1] <= S) ++j;
		while (j >= i && A[j + j - i + 1] - A[j] > S) --j;
		cout << 2 * (j - i + 1) << '\n';
	}
	return 0;
}
