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

int besthub(int R, int L, int X[], ll B) {
	ll sum = 0; int ans = 0;
	for (int i = 0, j = 0; i < R; i++) {
		while (j < R && sum <= B)
			++j, sum += X[j] - X[(i + j) >> 1];
		sum -= X[(i + j + 1) >> 1] - X[i], ans = max(ans, j - i);
	}
	return ans;
}
