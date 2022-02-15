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

string s[100000];
unordered_map<string, int> mp;
unordered_set<string> ss;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Y, x; ll ans = 0; string t;
    cin >> N >> Y;
    for (int i = 0; i < N; i++) cin >> s[i];
    for (int i = 0; i < N; i++) cin >> x, mp[s[i]] = x;
    for (int i = 0; i < Y; i++) cin >> t, ss.insert(t);
    for (auto i : ss) ans += mp[i];
    cout << ans << '\n';
    return 0;
}
