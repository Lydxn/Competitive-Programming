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

int a[1000000], na[1000000];
vector<pii> idx;
bool vis[1000001];
vector<int> idk;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	bool bad = true;
	for (int i = 0; i < N; i++) bad &= a[0] == a[i];

	if (bad) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < N; i++)
		if (!vis[a[i]]) idx.emplace_back(i, a[i]), vis[a[i]] = true;

	sort(idx.begin(), idx.end());
	for (int i = 0, sz = idx.size(); i < sz; i++)
		na[idx[i].first] = idx[(i + 1) % sz].second;

	for (int i = 1; i <= N; i++)
		if (!vis[i]) idk.push_back(i);
	for (int i = 0, j = 0; i < N; i++)
		if (na[i] == 0) na[i] = idk[j++];
	for (int i = 0; i < N; i++)
		cout << na[i] << ' ';
	cout << '\n';
	return 0;
}
