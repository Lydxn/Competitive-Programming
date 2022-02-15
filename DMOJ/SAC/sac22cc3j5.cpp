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

char c[101];
string dp[10001], b[101];
bool has[10001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M; string s;
    cin >> N >> M >> s; s = "?" + s;
    for (int i = 1; i <= N; i++) cin >> c[i] >> b[i];
    has[0] = true;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int sz = b[j].size();
            if (i - sz + 1 <= 0) continue;
            if (s.substr(i - sz + 1, sz) == b[j] && has[i - sz]) {
                if (!has[i] || dp[i - sz].size() + 1 < dp[i].size()) dp[i] = dp[i - sz] + c[j];
                else if (dp[i - sz].size() + 1 == dp[i].size()) dp[i] = min(dp[i], dp[i - sz] + c[j]);
                has[i] = true;
            }
        }
    }
    cout << dp[M] << '\n';
    return 0;
}
