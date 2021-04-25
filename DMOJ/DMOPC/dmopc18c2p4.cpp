#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int d[500000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, l = 0, r = 0, ans = INT_MAX; ll M, sum = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> d[i];
    
    while (l < N && r < N) {
        while (sum < M && r < N) sum += d[r++];
        while (sum >= M && l < N) ans = min(ans, r - l), sum -= d[l++];
    }
    
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return 0;
}
