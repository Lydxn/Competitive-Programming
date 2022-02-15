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

struct node {
    int r, c; ll v;
    bool operator< (const node &n) const { return v > n.v; }
};

int C[1500][1500], dst[1500][1500];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    priority_queue<node> q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> C[i][j];
    memset(dst, INF, sizeof(dst));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (C[i][j]) q.push({i, j, C[i][j]}), dst[i][j] = 0;
    while (!q.empty()) {
        auto [r, c, v] = q.top(); q.pop();
        if (dst[r][c] == K) continue;
        for (auto [dr, dc] : dir) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || dst[nr][nc] != INF) continue;
            C[nr][nc] = C[r][c], dst[nr][nc] = dst[r][c] + 1;
            q.push({nr, nc, dst[nr][nc] * 1000000000LL + C[nr][nc]});
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cout << C[i][j] << " \n"[j == M - 1];
    return 0;
}
