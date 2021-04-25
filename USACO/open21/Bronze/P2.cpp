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

unordered_map<string, int> mp;
char ans[100][100];
string p[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, N; string s;
	cin >> K >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans[i][j] = '?';
	for (int i = 0; i < N; i++) cin >> s, mp[s] = i, ans[i][i] = 'B';
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) cin >> p[j];
		for (int j = 0; j < N; j++) {
			bool flag = false;
			for (int k = j + 1; k < N; k++) {
				flag |= p[k - 1].compare(p[k]) > 0;
				if (flag) ans[mp[p[j]]][mp[p[k]]] = '0', ans[mp[p[k]]][mp[p[j]]] = '1';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << ans[i][j];
		cout << '\n';
	}
	return 0;
}