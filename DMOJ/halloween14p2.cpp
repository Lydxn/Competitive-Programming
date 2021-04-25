#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p[500001], c[500001], dp[500001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, idx = 1; ll W; char op;
    cin >> N >> W;
    
    while (N--) {
        cin >> op;
        if (op == 'D') --idx;
        else {
            cin >> p[idx] >> c[idx];
            p[idx] += p[idx - 1], c[idx] += c[idx - 1];
            cout << (dp[idx] = max(dp[idx - 1], c[idx] - c[lower_bound(p, p + idx + 1, p[idx] - W) - p])) << '\n';
            ++idx;
        }
    }
    return 0;
}
