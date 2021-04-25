#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
set<int> zeros;
vector<int> cur;
bool S[500001];

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1, a = a * a % MOD;
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, l, r; ll sum = 0; char ch;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> ch; S[i] = ch == '1';
        if (!S[i]) zeros.insert(i);
        else sum = (sum + modpow(2, N - i)) % MOD;
    }

    while (M--) {
        cin >> l >> r;
        cur.clear();
        for (auto it = zeros.lower_bound(l); it != zeros.upper_bound(r); it++) cur.push_back(*it);
        for (int i : cur) zeros.erase(i), sum = (sum + modpow(2, N - i)) % MOD;
        cout << sum << '\n';
    }
    return 0;
}
