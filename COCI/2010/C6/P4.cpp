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

string S[100];
bool alpha[128], vis[128];
int adj[128][128], ord[26], pos[128], oidx;

void dfs(int l, int r, int dep) {
	if (dep == 10 || l == r) return;
	for (int i = l; i < r; i++)
		if (S[i][dep] != S[i + 1][dep] && S[i][dep] * S[i + 1][dep] > 0)
			adj[S[i][dep]][S[i + 1][dep]] = true;
	for (int i = l; i <= r; ) {
		int cur = i;
		while (i <= r && S[cur][dep] == S[i][dep]) ++i;
		dfs(cur, i - 1, dep + 1);
	}
}

void dfs2(int cur) {
	vis[cur] = true;
	for (int i = 0; i < 128; i++)
		if (adj[cur][i] && !vis[i]) dfs2(i);
	pos[cur] = oidx, ord[oidx++] = cur;
}

void dfs3(int cur) {
	vis[cur] = true;
	for (int i = 0; i < 128; i++)
		if (adj[cur][i]) dfs3(i);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		for (char c : S[i]) alpha[c] = true;
		while (S[i].size() < 10) S[i] += '\0';
	}
	
	dfs(0, N - 1, 0);
	for (int i = 0; i < 128; i++)
		if (alpha[i] && !vis[i]) dfs2(i);
		
	for (int i = 0; i < 128; i++)
		for (int j = 0; j < 128; j++)
			if (adj[i][j] && pos[i] < pos[j]) { cout << "!\n"; return 0; }
			
	for (int i = 1; i < oidx; i++)
		if (!adj[ord[i]][ord[i - 1]]) { cout << "?\n"; return 0; }
		
	memset(vis, false, sizeof(vis)); dfs3(ord[oidx - 1]);
	for (int i = 0; i < 128; i++)
		if (alpha[i] && !vis[i]) { cout << "?\n"; return 0; }
	
	for (int i = oidx - 1; i >= 0; i--) cout << (char) ord[i];
	cout << '\n';
	return 0;
}
