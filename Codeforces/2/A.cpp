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

unordered_map<string, int> mp, mp2;
string s[1000]; int t[1000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> t[i], mp[s[i]] += t[i];
    int mx = 0;
    for (auto [k, v] : mp) mx = max(mx, v);
    for (int i = 0; i < n; i++) {
        mp2[s[i]] += t[i];
        if (mp2[s[i]] >= mx && mp[s[i]] == mx) {
            cout << s[i] << '\n';
            break;
        }
    }
    return 0;
}
