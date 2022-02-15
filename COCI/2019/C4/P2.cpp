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

int h[300000], cnt[1000001], b[1000001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K, mx = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> h[i], ++cnt[h[i]], mx = max(mx, h[i]);
    for (int i = K + 1; i <= mx; i++)
        if (cnt[i])
            for (int j = K; j <= mx; j += i)
                b[j] += cnt[i];
    for (int i = 0; i < N; i++) cout << b[h[i]] - (K == 0) << " \n"[i == N - 1];
    return 0;
}