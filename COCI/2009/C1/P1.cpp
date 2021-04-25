#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a[8];
	for (int i = 0; i < 8; i++) cin >> a[i];
	cout << (is_sorted(a, a + 8) ? "ascending" : is_sorted(a, a + 8, greater<int>()) ? "descending" : "mixed") << '\n';
	return 0;
}
