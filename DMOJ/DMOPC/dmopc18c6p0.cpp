#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a[4]; vector<int> d;
	for (int i = 1; i <= 3; i++) {
		cin >> a[i];
		if (a[i]) d.push_back(a[i]);
	}

	cout << (d.size() == 3 || (d.size() == 2 && a[d[0]] == d[1] && a[d[1]] == d[0]) ? "NO" : "YES") << '\n';
	return 0;
}
