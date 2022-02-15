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

string s[10000];
int dp[10000], pos[10000][26];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K, ans = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < K; j++) pos[i][s[i][j] - 'A'] = j;
    }
    for (int i = 0; i < K; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            bool ok = true;
            for (int k = 0; k < N; k++) ok &= pos[k][s[0][j] - 'A'] < pos[k][s[0][i] - 'A'];
            if (ok) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
