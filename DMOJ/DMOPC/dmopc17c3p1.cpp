#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N, A, ans = INT_MAX;
	cin >> N;
	while (N--) cin >> A, ans = min(ans, A);
	
	cout << ans << '\n';
	return 0;
}
