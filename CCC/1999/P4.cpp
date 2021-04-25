#include <bits/stdc++.h>

using namespace std;

int dist[101][101];
queue<pair<int, int>> q;
pair<int, int> dir[8] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c, pr, pc, kr, kc;
    cin >> n;
    
    while (n--) {
        cin >> r >> c >> pr >> pc >> kr >> kc;
        
        for (int i = 0; i <= r; i++) fill(dist[i], dist[i] + c + 1, INT_MAX);
        queue<pair<int, int>>().swap(q);
        dist[kr][kc] = 0, q.emplace(kr, kc);
        
        while (!q.empty()) {
            int cr = q.front().first, cc = q.front().second; q.pop();
            for (auto d : dir) {
                int nr = cr + d.first, nc = cc + d.second;
                if (nr > 0 && nr <= r && nc > 0 && nc <= c && dist[cr][cc] + 1 < dist[nr][nc]) {
                    dist[nr][nc] = dist[cr][cc] + 1;
                    q.emplace(nr, nc);
                }
            }
        }
        
        for (int i = pr + 1, ans = 1; i < r; i++, ans++) {
            if (ans >= dist[i][pc] && (ans - dist[i][pc]) % 2 == 0) {
                cout << "Win in " << ans << " knight move(s).\n";
                goto next;
            }
        }
        
        for (int i = pr + 1, ans = 0; i <= r; i++, ans++) {
            if (ans >= dist[i][pc] && (ans - dist[i][pc]) % 2 == 0) {
                cout << "Stalemate in " << ans << " knight move(s).\n";
                goto next;
            }
        }
        
        cout << "Loss in " << r - pr - 1 << " knight move(s).\n";
        next:;
    }
    return 0;
}
