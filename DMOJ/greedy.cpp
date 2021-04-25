#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int, int> f[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
    int N, M; ll ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> f[i].first >> f[i].second;
    
    sort(f, f + N);
    for (int i = 0; i < N && M > 0; i++) {
        int buy = M - f[i].second < 0 ? M : f[i].second;
        ans += f[i].first * buy;
        M -= buy;
    }
    
    cout << ans << '\n';
	return 0;
}
