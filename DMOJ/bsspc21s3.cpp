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

ll psa[1000001], dp[1000001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K, a;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a, psa[i] = psa[i - 1] + a;
    for (int i = K; i <= N; i++) dp[i] = max(0LL, psa[i] - psa[i - K] + dp[i - K]);
    cout << *max_element(dp + 1, dp + N + 1) << '\n';
    return 0;
}
