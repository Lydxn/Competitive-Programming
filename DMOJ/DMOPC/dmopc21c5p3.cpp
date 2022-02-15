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

const int MAXN = 100000;
bitset<MAXN + 1> dp, msk;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    msk.set(); msk[0] = msk[1] = 0;
    for (int i = 2; i * i <= MAXN; i++)
        if (msk[i])
            for (int j = i * i; j <= MAXN; j += i)
                msk[j] = 0;
    for (int i = 1; i <= MAXN; i++)
        if (!dp[i]) dp |= msk << i;

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N < 3) { cout << "-1\n"; continue; }
        for (int i = 1; i <= N - 3; i++) cout << i << ' ';
        if (dp[N]) cout << N - 2 << ' ' << N - 1 << ' ' << N << '\n';
        else if (dp[N - 1]) cout << N - 2 << ' ' << N << ' ' << N - 1 << '\n';
        else cout << N << ' ' << N - 2 << ' ' << N - 1 << '\n';
    }
    return 0;
}
