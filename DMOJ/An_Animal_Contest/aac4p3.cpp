#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

ll x[100000], y[100000], k[20], d[20];
unordered_map<ll, int> cnt;
set<pii> seen;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M; ll ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < M; i++) cin >> k[i] >> d[i];
    for (int i = 0; i < M; i++) {
        pii s = {k[i] / __gcd(k[i], d[i]), d[i] / __gcd(k[i], d[i])};
        if (seen.count(s)) continue;
        seen.insert(s);

        cnt.clear();
        for (int j = 0; j < N; j++)
            ++cnt[x[j] * k[i] - y[j] * d[i]];
        for (auto [_, v] : cnt) ans += 1LL * v * (v - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}
