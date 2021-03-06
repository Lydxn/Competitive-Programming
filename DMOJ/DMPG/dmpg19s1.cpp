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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, C;
	cin >> a >> b >> c >> C;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 100; k++)
				if (a * i + b * j + c * k == C)
					{ cout << "QUEST CLEARED\n"; return 0; }
	cout << "TRY AGAIN\n";
	return 0;
}
