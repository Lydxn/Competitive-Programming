#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXW = 5000;
ll dp[2][MAXW + 1];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	
	int N, M, n, v, p, c, f; ll ans = LLONG_MIN;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
	    cin >> n >> v >> p;
	    for (int j = 0; j <= MAXW; j++) {
	        for (ll k = 0; k <= n && j >= k * v; k++) {
	            dp[i & 1][j] = max(dp[i & 1][j], dp[(i & 1) ^ 1][j - k * v] + k * p);
	        }
	    }
	}
	
	while (M--) {
	    cin >> c >> f;
	    ans = max(ans, dp[N & 1][c] - f);
	}
	
	cout << ans << '\n';
    return 0;
}
