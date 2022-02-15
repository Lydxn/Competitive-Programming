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

char g[2000][2000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> g[i][j];
    for (int i = 0; i < (N + 1) / 2; i++) {
        for (int j = 0; j < (M + 1) / 2; j++) {
            vector<pii> v = {{i, j}, {N - i - 1, j}, {i, M - j - 1}, {N - i - 1, M - j - 1}};
            char ch = 0;
            for (auto &[r, c] : v) {
                if (g[r][c] != '.') {
                    if (ch != 0 && ch != g[r][c]) { cout << "-1\n"; return 0; }
                    ch = g[r][c];
                }
            }
            for (auto &[r, c] : v)
                g[r][c] = ch ? ch : 'a';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << g[i][j];
        cout << '\n';
    }
    return 0;
}
