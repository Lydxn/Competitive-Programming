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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K, ans = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> s[i];
    for (int i = 0; i < 1 << K; i++) {
        int cur = INF;
        for (int j = 0; j < N; j++) {
            int x = 0;
            for (int k = 0; k < K; k++) x += (s[j][k] == 'T') == ((i >> k) & 1);
            cur = min(cur, x);
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}
