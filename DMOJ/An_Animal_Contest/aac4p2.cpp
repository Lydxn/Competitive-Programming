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

ll a[200001], L[200001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    L[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        L[i] = min(1000000001LL, lcm(L[i - 1], a[i]));
    }
    while (Q--) {
        int t; cin >> t;
        int l = 1, r = N, m;
        while (l <= r) {
            m = (l + r) >> 1;
            if (t % L[m] == 0) l = m + 1;
            else r = m - 1;
        }
        cout << (l > N ? -1 : l) << '\n';
    }
    return 0;
}