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

int B[100000], l, r;
bool done[200000];

void printl() {
	while (done[l]) ++l;
	cout << l << ' ', done[l++] = true;
}

void printr() {
	while (done[r]) --r;
	cout << r << ' ', done[r--] = true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> B[i];
	
	l = 1, r = 2 * N - 1;
	cout << B[0] << ' ', done[B[0]] = true;
	for (int i = 1; i < N; i++) {
		if (!done[B[i]]) {
			if (B[i] < B[i - 1]) printl();
			else printr();
			cout << B[i] << ' ', done[B[i]] = true;
		} else {
			if (B[i] < B[i - 1]) printl(), printl();
			else if (B[i] > B[i - 1]) printr(), printr();
			else printl(), printr();
		}
	}
	cout << '\n';
	return 0;
}
