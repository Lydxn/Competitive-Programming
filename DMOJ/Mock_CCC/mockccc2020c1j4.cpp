#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool lights[1000000];
int dist[1000000];
queue<int> q;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; ll ans = 0; char ch;
    cin >> N;

    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < N; i++) {
        cin >> ch;
        if (ch == '1') lights[i] = 1, dist[i] = 0, q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur - 1 >= 0 && !lights[cur - 1] && dist[cur - 1] == -1) dist[cur - 1] = dist[cur] + 1, q.push(cur - 1);
        if (cur + 1 < N && !lights[cur + 1] && dist[cur + 1] == -1) dist[cur + 1] = dist[cur] + 1, q.push(cur + 1);
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] != -1) ans += dist[i];
    }
    cout << ans << '\n';
    return 0;
}
