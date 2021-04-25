#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<int> uset;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		uset.clear();
		while (n--) cin >> a, uset.insert(a);
		cout << uset.size() << '\n';
	}
	return 0;
}
