#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, string> par;
unordered_map<string, int> sz;
string find(string v) { return v == par[v] ? v : par[v] = find(par[v]); }
bool join(string u, string v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string a, b; char op;
	for (int _ = 0; _ < 5; _++) {
		cin >> N;
		while (N--) {
			cin >> op >> a >> b;
			if (!par.count(a)) par[a] = a;
			if (!par.count(b)) par[b] = b;
			if (!sz.count(a)) sz[a] = 1;
			if (!sz.count(b)) sz[b] = 1;

			if (op == 'p') join(a, b);
			else cout << (find(a) == find(b) ? "connected" : "not connected") << '\n';
		}
		par.clear(), sz.clear();
	}
	return 0;
}
