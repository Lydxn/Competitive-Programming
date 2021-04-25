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

string S[100000];
int tmp[100000], idxs[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];

	string ans = "";
	for (char c = 'z'; c >= 'a'; c--) {
		while (true) {
			for (int i = 0; i < N; i++) {
				int idx = S[i].find(c, idxs[i]);
				if (idx == -1) goto nxt;
				tmp[i] = idx + 1;
			}
			memcpy(idxs, tmp, N << 2);
			ans += c;
		}
		nxt:;
	}
	cout << (ans.empty() ? "-1" : ans) << '\n';
	return 0;
}
