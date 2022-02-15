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

int magic[] = {0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 2, 2, 4, 4, 2, 4, 4, 4, 5, 6, 7, 7, 8, 5, 6, 9, 8, 9, 10, 7, 9, 7, 10, 8, 11, 9, 10, 12, 16, 12, 9, 15, 13, 13, 12, 13, 16, 11, 14, 14, 19, 18, 18, 17, 18, 18, 17, 20, 17, 19, 19, 26, 20, 21, 20, 20, 23, 22, 25, 21, 20, 25, 23, 35, 23, 25, 24, 32, 25, 29, 27, 27, 28, 30, 27, 36, 28, 27, 28, 34, 28, 29, 29, 32, 37, 32, 36, 26, 35, 28, 30};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << magic[n] << '\n';
    return 0;
}
