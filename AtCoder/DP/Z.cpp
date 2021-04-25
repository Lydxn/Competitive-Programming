#include <bits/stdc++.h>
#define f(a, b) (dp[a] - dp[b] + h[a] * h[a] - h[b] * h[b]) / (2.0 * (h[a] - h[b]))

using namespace std;

typedef long long ll;

int q[200001]; ll h[200001], dp[200001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, bptr = 1, fptr = 1; ll C;
    cin >> N >> C;
    for (int i = 1; i <= N; i++) cin >> h[i];
    
    q[1] = 1;
    for (int i = 2; i <= N; i++) {
        while (fptr < bptr && f(q[fptr], q[fptr + 1]) < h[i]) ++fptr;
        dp[i] = dp[q[fptr]] + (h[i] - h[q[fptr]]) * (h[i] - h[q[fptr]]) + C;
        while (fptr < bptr && f(q[bptr], i) < f(q[bptr - 1], q[bptr])) --bptr;
        q[++bptr] = i;
    }
    
    cout << dp[N] << '\n';
    return 0;
}
