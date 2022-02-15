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

ll a[100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; ll mn = INFL, mx = 0;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        cout << "? 1 " << i << '\n' << flush;
        cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
    a[1] = mx == N ? 1 : mn;
    for (int i = 2; i <= N; i++) a[i] /= a[1];
    cout << '!';
    for (int i = 1; i <= N; i++) cout << ' ' << a[i];
    cout << '\n' << flush;
    return 0;
}
