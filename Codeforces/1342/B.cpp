#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; string t;
	cin >> T;
	while (T--) {
		cin >> t;
		string s = "";
		if (t == string(t.size(), '0') || t == string(t.size(), '1')) cout << t << '\n';
		else {
			for (char _ : t) s += "10";
			cout << s << '\n';
		}
	}
	return 0;
}
