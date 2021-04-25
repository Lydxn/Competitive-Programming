#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll solve(ll a, ll b) {
    ll res = 0;
    for (ll i = b; i <= a; i *= b) res += a / i;
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll a, b, ans = INT_MAX;
    cin >> a >> b;

    vector<pii> fact;
    for (ll i = 2; i <= a; i++) {
        if (a % i == 0) {
            int cnt = 0;
            while (a % i == 0) a /= i, ++cnt;
            fact.emplace_back(i, cnt);
        }
    }

    for (auto a : fact) ans = min(ans, solve(b, a.first) / a.second);
    cout << ans << '\n';
    return 0;
}
