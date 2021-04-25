#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, A, mn1 = INT_MAX, mx1 = INT_MIN, mn2 = INT_MAX, mx2 = INT_MIN;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A, mn1 = min(mn1, A + i), mx1 = max(mx1, A + i), mn2 = min(mn2, A - i), mx2 = max(mx2, A - i);
	cout << max(mx1 - mn1, mx2 - mn2) << '\n';
	return 0;
}
