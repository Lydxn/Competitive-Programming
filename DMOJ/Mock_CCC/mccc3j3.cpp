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

int cnts[26], cntt[26];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string S, T; int x, y;
    cin >> x >> y >> S >> T;
    for (char c : S) ++cnts[c - 'A'];
    for (char c : T) ++cntt[c - 'A'];
    int mn = T[0] - 'A', mx = S[0] - 'A';
    for (char c : T)
        if (cnts[mn] > cnts[c - 'A']) mn = c - 'A';
    for (char c : S)
        if (cnts[mx] < cnts[c - 'A']) mx = c - 'A';
    ll ans = 0; ++cntt[mx], --cntt[mn];
    for (int i = 0; i < 26; i++) ans += 1LL * cnts[i] * cntt[i];
    cout << ans << '\n';
    return 0;
}
