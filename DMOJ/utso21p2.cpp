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

int A[101], m[101], aidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, N = 1;
	cin >> K;
	while (N * (N + 1) / 2 < K) ++N;

	vector<int> c;
	int L = N * (N + 1) / 2 - K;
	for (int i = N; i; i--) {
		int m = i * (i + 1) / 2;
		while (L - m >= 0) L -= m, c.push_back(i);
	}

	for (int i = 0; i < N; i++) A[i] = 1;
	for (int i : c) {
		for (int j = 0; j < i; j++)  A[aidx++] = 2;
		aidx++;
	}

	cout << N << '\n';
	for (int i = 0; i < N; i++) cout << A[i] << ' ';
	cout << '\n';
	return 0;
}
