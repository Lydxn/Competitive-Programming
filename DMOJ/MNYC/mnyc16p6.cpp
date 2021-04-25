#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, pair<int, int>> umap;
int BIT[10001];

void update(int i, int v) { for (; i <= 10000; i += i & -i) BIT[i] += v; }
int query(int i) { int res = 0; for (; i > 0; i -= i & -i) res += BIT[i]; return res; }
int query(int l, int r) { return query(r) - query(l - 1); }
int mass(string& s) { int res = 0; for (int i = 0; i < int(s.size()); i++) res += s[i] - 'a' + 1; return res; }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, t1, t2, sz = 0; string R, X, Y; char op;
	cin >> C;

	while (C--) {
		cin >> op;
		switch (op) {
			case 'A':
				cin >> R;
				if (umap.count(R)) cout << "Can't add " + R << '\n';
				else update(umap[R].second = ++sz, umap[R].first = mass(R));
				break;
			case 'S':
				cin >> X >> Y;
				t1 = umap[X].first - umap[Y].first;
				update(umap[X].second, -t1); update(umap[Y].second, t1);
				t1 = umap[X].second, umap[X].second = umap[Y].second, umap[Y].second = t1;
				break;
			case 'M':
				cin >> X >> Y; t1 = umap[X].second, t2 = umap[Y].second;
				cout << (t1 < t2 ? query(t1, t2) : query(t2, t1)) << '\n';
				break;
			case 'R':
				cin >> X >> Y;
				t1 = mass(Y), t2 = umap[X].second;
				update(t2, t1 - umap[X].first);
				umap.erase(X); umap[Y] = {t1, t2};
				break;
			case 'N':
				cout << sz << '\n';
				break;
		}
	}
	return 0;
}
