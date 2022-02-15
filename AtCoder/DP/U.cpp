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

int a[16][16];
ll s[1 << 16], dp[1 << 16];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    for (int i = 0; i < 1 << N; i++)
        for (int x = 0; x < N; x++)
            if (i >> x & 1)
                for (int y = 0; y < x; y++)
                    if (i >> y & 1)
                    s[i] += a[x][y];
    for (int i = 0; i < 1 << N; i++)
        for (int j = i; j; j = (j - 1) & i)
            dp[i] = max(dp[i], s[j] + dp[i ^ j]);
    cout << dp[(1 << N) - 1] << '\n';
    return 0;
}
