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

bool add[1000001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, X, cnt; ll d;
    cin >> N >> X;
    if (N % 2 == 0) {
        d = N / 2 - X + 1LL * (N / 2) * (N / 2 + 1) / 2;
        cnt = N / 2, d = d / 2 + d % 2;
    } else {
        d = N / 2 + 1 - X + 1LL * (N / 2) * (N / 2 + 1) / 2;
        if (d % 2 == 0) d /= 2, cnt = N / 2;
        else {
            d = N / 2 + 1 - X + 1LL * (N / 2 + 1) * (N / 2 + 2) / 2;
            d /= 2, cnt = N / 2 + 1;
        }
    }
    for (int i = cnt; i >= 0; i--) {
        if (d <= i) { add[d] = true; break; }
        add[i] = true, d -= i;
    }
    vector<int> pos, neg, ans;
    for (int i = 1; i <= cnt; i++) (add[i] ? pos : neg).push_back(i);
    while (!pos.empty() || !neg.empty()) {
        for (int x; !pos.empty() && X + (x = pos.back()) <= N; pos.pop_back())
            X += x, ans.push_back(x);
        for (int x; !neg.empty() && X - (x = neg.back()) >= 1; neg.pop_back())
            X -= x, ans.push_back(-x);
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << '\n';
    return 0;
}
