#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

priority_queue<int, vector<int>, greater<int>> pq;
unordered_map<string, int> to_num = {{"BLUE", 0}, {"PINK", 1}, {"GREEN", 2}};
string to_str[3] = {"BLUE", "PINK", "GREEN"};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, m; string op, c;
	cin >> Q;

	while (Q--) {
		cin >> op;
		if (op == "ADD") {
			cin >> c >> m;
			pq.push(to_num[c] << 29 | m);
		} else {
			if (pq.empty()) cout << "NONE\n";
			else {
				c = to_str[pq.top() >> 29], m = pq.top() & 536870911; pq.pop();
				cout << c << ' ' << m << '\n';
			}
		}
	}
	return 0;
}
