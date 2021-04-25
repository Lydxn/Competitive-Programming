#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string x, cur; int sum = 0;
	while (cin >> x) {
	    cur = "";
	    for (int i = 0; i < int(x.size()); i++) if (x[i] == '-' || isdigit(x[i])) cur.push_back(x[i]);
	    if (!cur.empty()) sum += stoi(cur);
	}

	cout << sum << '\n';
	return 0;
}
