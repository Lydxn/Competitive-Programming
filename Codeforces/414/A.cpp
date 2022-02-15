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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    if (n == 1) { cout << (k == 0 ? 1 : -1) << '\n'; return 0; }
    if (k < n / 2) { cout << "-1\n"; return 0; }
    for (int i = 1; i < n / 2; i++) cout << i * 2 + 200000000 << ' ' << i * 2 + 200000001 << ' ';
    if (n % 2) cout << k - (n / 2 - 1) << ' ' << (k - (n / 2 - 1)) * 2 << " 1000000000\n";
    else cout << k - (n / 2 - 1) << ' ' << (k - (n / 2 - 1)) * 2 << '\n';
    return 0;
}
