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

int a[153], b[153];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, ans = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> a[i] >> b[i], --a[i], --b[i];
    for (int i = 0; i < 1 << N; i++) {
        bool bad = false;
        for (int j = 0; j < M; j++)
            bad |= ((i >> a[j]) & 1) && ((i >> b[j]) & 1);
        if (!bad) ans = max(ans, __builtin_popcount(i));
    }
    cout << ans << '\n';
    return 0;
}
