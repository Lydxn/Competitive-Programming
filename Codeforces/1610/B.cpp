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

int a[200000], n;

bool test(int x) {
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (a[i] != x) v.push_back(a[i]);
    int vs = v.size();
    for (int i = 0; i < vs; i++)
        if (v[i] != v[vs - i - 1]) return false;
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        bool bad = false;
        for (int i = 0; i < n / 2; i++)
            if (a[i] != a[n - i - 1])
                { bad = !test(a[i]) && !test(a[n - i - 1]); break; }
        cout << (bad ? "NO" : "YES") << '\n';
    }
    return 0;
}
