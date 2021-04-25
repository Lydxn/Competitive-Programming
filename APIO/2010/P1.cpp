#include <bits/stdc++.h>
#define f(i, j) (dp[i] - dp[j] + a * x[i] * x[i] - a * x[j] * x[j] - b * x[i] + b * x[j]) / (2.0 * a * (x[i] - x[j]))

using namespace std;

typedef long long ll;

ll dp[1000001], x[1000001], dq[1000001];
int fptr = 1, bptr = 1;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; ll a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++) cin >> x[i], x[i] += x[i - 1];

    for (int i = 1; i <= n; i++) {
        while (fptr < bptr && f(dq[fptr], dq[fptr + 1]) < x[i]) ++fptr;
        int sum = x[i] - x[dq[fptr]];
        dp[i] = dp[dq[fptr]] + a * sum * sum + b * sum + c;
        while (fptr < bptr && f(dq[bptr], i) < f(dq[bptr - 1], dq[bptr])) --bptr;
        dq[++bptr] = i;
    }

    cout << dp[n] << '\n';
    return 0;
}
