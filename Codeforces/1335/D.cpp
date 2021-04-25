#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; string line;
	cin >> t;
	for (int i = 0; i < t * 9; i++) {
		cin >> line;
		replace(line.begin(), line.end(), '1', '2');
		cout << line << '\n';
	}
	return 0;
}
