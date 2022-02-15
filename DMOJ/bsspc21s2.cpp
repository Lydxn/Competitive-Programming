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

int a[5000], b[5000], c[5000], d[5000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K, Q, R, C;
    cin >> N >> K >> Q;
    for (int i = 0; i < K; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    while (Q--) {
        cin >> R >> C;
        for (int i = K - 1; i >= 0; i--) {
            if (a[i] <= R && R <= c[i] && b[i] <= C && C <= d[i]) {
                R -= a[i], C -= b[i];
                int nr = (c[i] - a[i]) - C, nc = R;
                R = nr + a[i], C = nc + b[i];
            }
        }
        cout << 1LL * (R - 1) * N + C << '\n';
    }
    return 0;
}
