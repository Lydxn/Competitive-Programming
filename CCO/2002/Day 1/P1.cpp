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

unordered_map<string, int> cnt[3];

void init(int lines, int type) {
	string line;
	while (lines--) {
		while (true) {
			getline(cin, line);
			if (line == "ENDMESSAGE") break;
			for (int i = 0; i < int(line.size()) - 2; i++)
				++cnt[type][line.substr(i, 3)];
		}
	}
}

double similarity(int f1, int f2) {
	int a = 0, b = 0, c = 0;
	for (auto i : cnt[f1]) a += i.second * cnt[f2][i.first];
	for (auto i : cnt[f1]) b += i.second * i.second;
	for (auto i : cnt[f2]) c += i.second * i.second;
	return a / sqrt(b * c);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int s, n, c; string line;
	cin >> s >> n >> c; cin.ignore();

	while (s--) {
		while (true) {
			getline(cin, line);
			if (line == "ENDMESSAGE") break;
			for (int i = 0; i < int(line.size()) - 2; i++)
				++cnt[0][line.substr(i, 3)];
		}
	}

	while (n--) {
		while (true) {
			getline(cin, line);
			if (line == "ENDMESSAGE") break;
			for (int i = 0; i < int(line.size()) - 2; i++)
				++cnt[1][line.substr(i, 3)];
		}
	}

	while (c--) {
		cnt[2].clear();
		while (true) {
			getline(cin, line);
			if (line == "ENDMESSAGE") break;
			for (int i = 0; i < int(line.size()) - 2; i++)
				++cnt[2][line.substr(i, 3)];
		}

		double sim1 = similarity(2, 0), sim2 = similarity(2, 1);
		cout << fixed << setprecision(5) << sim1 << ' ' << sim2 << '\n';
		cout << (sim1 > sim2 ? "spam" : "non-spam") << '\n';
	}
	return 0;
}
