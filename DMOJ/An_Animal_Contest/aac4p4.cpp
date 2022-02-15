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

int k[2001], ans[2001][2001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, S, F, L, R, X = 0;
    cin >> N >> M >> S >> F >> L >> R;
    for (int i = 1; i <= M; i++) cin >> k[i];
    int idx = 0;
    for (int i = M; i; i--)
        if (k[i] == F)
            { idx = i; break; }

    int mx = N * M - (M - idx), tot = 0, row = S;
    if (L > mx) { cout << "-1\n"; return 0; }

    if (idx == 0) {
        if (S != F) { cout << "-1\n"; return 0; }
        else {
            X = L;
            for (int i = 1; i <= N; i++) {
                if (i == F) continue;
                for (int j = 1; j <= M; j++) {
                    if (++tot > X) goto nxt;
                    ans[i][j] = 1;
                }
            }
            goto done;
        }
    }

    if (R == 0) {
        if (S == F) goto done;
        else { cout << "-1\n"; return 0; }
    }

    X = max(1, L);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= (i == F ? idx : M); j++) {
            if (++tot == X) goto nxt;
            ans[i][j] = 1;
        }
    }
    nxt:;

    for (int i = 1; i < idx; i++)
        row = ans[row][i] ? k[i] : row;

    if (!ans[row][idx]) ans[row][idx] = 1;
    else {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= (i == F ? idx : M); j++)
                if (!ans[i][j])
                    { ans[i][j] = 1; goto done; }
    }

    done:;
    cout << X << '\n';
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cout << ans[i][j] << " \n"[j == M];
    return 0;
}
