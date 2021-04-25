#include <bits/stdc++.h>

using namespace std;

vector<int> digs;
unordered_set<int> cur, temp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int W, D, V, dig, target;
	cin >> W >> D;
	for (int i = 0; i < D; i++) cin >> dig, digs.push_back(dig);

	cin >> V;
	while (V--) {
		cin >> target; cur.clear();
		for (int d : digs) cur.insert(d);

		for (int i = 0; i < W; i++) {
			for (int c : cur) {
				for (int d : digs) {
					temp.insert(c * d);
					temp.insert(c + d);
				}
			}
			cur = temp; temp.clear();
		}
		cout << (cur.count(target) ? "Y" : "N") << '\n';
	}
	return 0;
}
