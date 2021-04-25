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

struct edge {
	int a, b;
	bool operator< (const edge &e) { return a < e.a || (a == e.a && b < e.b); }
} e[3000];
vector<int> adj[3001];
bool m[3001][3001];
vector<int> ans3(3, INF), ans4(4, INF), tmp;
bool three, four;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		e[i] = {min(a, b), max(a, b)};
		adj[a].push_back(b), adj[b].push_back(a);
		m[a][b] = m[b][a] = true;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			if (m[e[j].a][i] && m[e[j].b][i]) {
				tmp = {i, e[j].a, e[j].b};
				if (tmp < ans3) ans3 = tmp, three = true;
			}
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++)
			if (e[i].a != e[j].a && e[i].a != e[j].b && e[i].b != e[j].a && e[i].b != e[j].b) {
				tmp = {e[i].a, e[j].a, e[i].b, e[j].b}; sort(tmp.begin(), tmp.end());
				if (tmp < ans4) ans4 = tmp, four = true;
			}

	if (three) cout << "3\n" << ans3[0] << ' ' << ans3[1] << ' ' << ans3[2] << '\n';
	else if (four) cout << "4\n" << ans4[0] << ' ' << ans4[1] << ' ' << ans4[2] << ' ' << ans4[3] << '\n';
	else cout << "-1\n";
	return 0;
}
