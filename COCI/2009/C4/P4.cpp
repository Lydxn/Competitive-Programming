#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int h[1000000], mn[1000000], mx[1000000];
deque<int> dq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> h[i];

	for (int i = 0; i < N; i++) {
		while (!dq.empty() && dq.front() <= i - X) dq.pop_front();
		while (!dq.empty() && h[dq.back()] >= h[i]) dq.pop_back();
		dq.push_back(i);
		if (i >= X - 1) mn[i - X + 1] = h[dq.front()];
	}

	ll a0 = 0; int a1 = 0;

	dq.clear();
	for (int i = 0; i < N; i++) {
		while (!dq.empty() && dq.front() <= i - X) dq.pop_front();
		while (!dq.empty() && mn[dq.back()] <= mn[i]) dq.pop_back();
		if (i <= N - X) dq.push_back(i);
		mx[i] = mn[dq.front()], a0 += h[i] - mx[i];
	}

	for (int i = 0, pi = -1, px = -1; i < N; i++) {
		if (mx[i] != pi || i > px)
			++a1, pi = mx[i], px = i + X - 1;
	}

	cout << a0 << '\n' << a1 << '\n';
	return 0;
}
