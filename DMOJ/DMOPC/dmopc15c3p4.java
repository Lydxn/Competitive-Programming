#include <bits/stdc++.h>
#define sqdist(p1, p2) (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)

using namespace std;

typedef long long ll;

pair<ll, ll> country[3000];
ll dist[3000];
bool vis[3000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, X, Q; ll qu;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> country[i].first >> country[i].second;

    cin >> X;
    memset(dist, 0x3f, sizeof(dist));
    dist[--X] = 0;

    for (int i = 0; i < N - 1; i++) {
        ll best = LLONG_MAX; int idx = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && dist[j] < best) best = dist[j], idx = j;
        }

        if (idx == -1) break;
        vis[idx] = true;

        for (int j = 0; j < N; j++) {
            if (j != idx) dist[j] = min(dist[j], dist[idx] + sqdist(country[idx], country[j]));
        }
    }
    sort(dist, dist + N);

    cin >> Q;
    while (Q--) {
        cin >> qu;
        cout << upper_bound(dist, dist + N, qu) - dist << '\n';
    }
    return 0;
}
