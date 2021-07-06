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

set<pair<pii, pii>> ss;
vector<pii> ans;
pii dir[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, y;
	cin >> N;
	while (N--) {
		cin >> x >> y;
		if ((x + y) % 4 == 0) {
			ss.insert({{x, y}, {x, y}});
			ss.insert({{x, y}, {x, y + 1}});
			ss.insert({{x, y + 1}, {x + 1, y + 1}});
			ss.insert({{x + 1, y + 1}, {x + 1, y}});
			ss.insert({{x + 1, y}, {x, y}});
		} else {
			ss.insert({{x - 1, y}, {x - 1, y + 1}});
			ss.insert({{x - 1, y + 1}, {x, y + 2}});
			ss.insert({{x, y + 2}, {x + 1, y + 2}});
			ss.insert({{x + 1, y + 2}, {x + 2, y + 1}});
			ss.insert({{x + 2, y + 1}, {x + 2, y}});
			ss.insert({{x + 2, y}, {x + 1, y - 1}});
			ss.insert({{x + 1, y - 1}, {x, y - 1}});
			ss.insert({{x, y - 1}, {x - 1, y}});
		}
	}

	int cur = 7, cx = (*ss.begin()).first.first, cy = (*ss.begin()).first.second;
	ans.emplace_back(cx, cy);
	while (true) {
		for (int i = cur; i < cur + 8; i++) {
			int nx = cx + dir[i % 8].first, ny = cy + dir[i % 8].second;
			if (ss.count(make_pair(make_pair(cx, cy), make_pair(nx, ny)))) {
				ans.emplace_back(nx, ny);
				cur = (find(dir, dir + 8, make_pair(cx - nx, cy - ny)) - dir + 1) % 8;
				cx = nx, cy = ny;
				break;
			}
		}
		if (cx == ans[0].first && cy == ans[0].second)
			break;
	}
	ans.pop_back();
	cout << ans.size() << '\n';
	for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
	return 0;
}
