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
const ll MOD = 1000000000039;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

const int LEN = 30;
vector<string> BIT[30001];
unordered_map<string, int> word;
string S;

int search(int l, int r, int idx, int x, bool upper) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (S[idx] + upper <= BIT[x][mid][idx]) r = mid;
		else l = mid + 1;
	}
	return l;
}

int solve(int x, int l, int r, int idx) {
	if (l >= r) return 0;
	if (idx == int(S.size())) return r - l;
	int bl = search(l, r, idx, x, false), br = search(l, r, idx, x, true);
	return r - l + solve(x, bl, br, idx + 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S;
		word[S] = i;
		for (int j = i; j <= N; j += j & -j) BIT[j].push_back(S);
	}

	for (int i = 1; i <= N; i++)
		sort(BIT[i].begin(), BIT[i].end());

	cin >> Q;
	while (Q--) {
		cin >> S; auto it = word.find(S);
		int x = it == word.end() ? N : it->second, ans = 0;
		for (; x; x -= x & -x) ans += solve(x, 0, BIT[x].size(), 0);
		cout << ans << '\n';
	}
	return 0;
}
