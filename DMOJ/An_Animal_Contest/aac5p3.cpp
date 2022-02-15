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

struct edge {
    int v, w;
    bool operator< (const edge &e) { return w < e.w; }
};

vector<edge> adj0[200001], adj[200001];
int s[200000], L[200001], R[200001];

void dfs(int cur, int p = 0, int l = 1, int r = 1e9) {
    L[cur] = l, R[cur] = r;
    sort(adj[cur].begin(), adj[cur].end());
    int sz = adj[cur].size();
    for (int i = 0; i < sz; i++) {
        if (adj[cur][i].v == p) continue;
        int cl = i == 0 ? 1 : (adj[cur][i].w + adj[cur][i - 1].w + 2) / 2;
        int cr = i == sz - 1 ? 1e9 : (adj[cur][i].w + adj[cur][i + 1].w) / 2;
        dfs(adj[cur][i].v, cur, max(l, cl), min(r, cr));
    }
}

void dfs0(int cur, int p = 0) {
    for (auto [v, w] : adj0[cur])
        if (v != p) dfs0(v, cur), adj[cur].push_back({v, w});
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K, a, b, d;
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> d;
        adj0[a].push_back({b, d}), adj0[b].push_back({a, d});
    }
    dfs0(1); dfs(1);
    for (int i = 0; i < K; i++) cin >> s[i];
    sort(s, s + K);
    for (int i = 1; i <= N; i++) {
        int l = lower_bound(s, s + K, L[i]) - s;
        int r = upper_bound(s, s + K, R[i]) - s - 1;
        cout << max(0, r - l + 1) << " \n"[i == N];
    }
    return 0;
}
