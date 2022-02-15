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

int a[1000000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M; string X;
    cin >> N >> M >> X;
    int mx = 0, mi = 0;
    for (int i = 0; i < M; i++) cin >> a[i], mx = max(mx, a[i]);
    for (int i = 0, j = 0; i < N; i++) {
        if (X[i] != '0') continue;
        if (a[j++] == mx) mi = i;
    }
    for (int i = mi; i < mi + N; i++)
        if (X[i % N] != '0') cout << X[i % N];
    cout << '\n';
    return 0;
}