#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n; string x, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> x; a = b = "";
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (x[i] == '0') a.push_back('0'), b.push_back('0');
			else if (x[i] == '1') {
				if (flag) a.push_back('0'), b.push_back('1');
				else a.push_back('1'), b.push_back('0');
				flag = true;
			}
			else {
				if (flag) a.push_back('0'), b.push_back('2');
				else a.push_back('1'), b.push_back('1');
			}
		}
		cout << a << '\n' << b << '\n';
	}
	return 0;
}
