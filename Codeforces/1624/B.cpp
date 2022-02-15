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

int sgn(int x) { return x ? -1 : x ? 1 : 0; }

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if ((2 * b - c > 0 && (2 * b - c) % a == 0) ||
            ((a + c) % 2 == 0 && (a + c) / 2 % b == 0) ||
            (2 * b - a > 0 && (2 * b - a) % c == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
