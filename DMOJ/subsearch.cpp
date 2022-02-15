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

int a[100001], f[100001], f2[100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, F; ll S;
    cin >> N >> F >> S;
    for (int i = 0; i < N; i++) cin >> a[i];
    ll g = 0, s = 0;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && s + a[j] <= S) s += a[j++];
        g += j - i, s -= a[i];
    }
    ll G = 0;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && f[a[j]] + 1 <= F) ++f[a[j++]];
        G += j - i, --f[a[i]];
    }
    ll gG = 0, s2 = 0;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && f2[a[j]] + 1 <= F && s2 + a[j] <= S) s2 += a[j], ++f2[a[j++]];
        gG += j - i, s2 -= a[i], --f2[a[i]];
    }
    cout << (g % MOD) * (G % MOD) % MOD * (gG % MOD) % MOD << '\n';
    return 0;
}
