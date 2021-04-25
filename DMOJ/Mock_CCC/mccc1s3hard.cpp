#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 200005, MOD = 1000000000007;
set<pair<ll, int>> ss;
pair<ll, int> arr[MAX];
ll p[MAX], h;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string S, s; int Q, x, ans, idx = 0; char op, c;
    cin >> S >> Q;

    p[0] = 1;
    for (int i = 1; i < MAX; i++) p[i] = p[i - 1] * 987654321 % MOD;

    h = 1;
    for (int i = 0; i < S.size(); i++) {
        h = (h + S[i] * p[i]) % MOD;
        ss.insert({h, idx});
    }
    arr[idx++] = {h, S.size()};

    while (Q--) {
        cin >> op;
        if (op == 'C') {
            cin >> x >> c; --x;
            ll cur = (arr[x].first + c * p[arr[x].second]) % MOD;
            ss.insert({cur, idx});
            arr[idx++] = {cur, arr[x].second + 1};
        } else {
            cin >> s;
            h = 1, ans = 9999999;
            for (int i = 0; i < s.size(); i++) {
                h = (h + s[i] * p[i]) % MOD;
                auto check = ss.lower_bound({h, INT_MIN});
                if ((*check).first == h) {
                    ans = (*check).second;
                } else break;
            }
            cout << (ans == 9999999 ? -1 : ans + 1) << '\n';
        }
    }
    return 0;
}
