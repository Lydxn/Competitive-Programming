// WIP

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

int a[1000001], b[1000001], dp[1000001], par[1000001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> a[i] >> b[i];
    memset(dp, INF, sizeof(dp)); dp[a[1]] = 0;
    for (int i = 1; i <= M; i++)
        if (dp[a[i]] + 1 < dp[b[i]])
            dp[b[i]] = dp[a[i]] + 1, par[b[i]] = a[i];
    vector<int> ans;
    for (int cur = b[M]; cur; cur = par[cur])
        ans.push_back(cur);
    assert(int(ans.size()) == dp[b[M]] + 1);
    cout << dp[b[M]] << '\n';
    for (int i = dp[b[M]] - 1; i >= 0; i--)
        cout << ans[i + 1] << ' ' << ans[i] << '\n';
    return 0;
}
