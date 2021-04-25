#include <bits/stdc++.h>

#define open(r1, c1, r2, c2) !(psa[r2 + 1][c2 + 1] - psa[r2 + 1][c1] - psa[r1][c2 + 1] + psa[r1][c1])

using namespace std;

int psa[2001][2001], dist[2000][2000];
char grid[2000][2000];
queue<pair<int, int>> q;
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int R, C, L, W;
    cin >> R >> C >> L >> W;
    
    char ch;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ch;
            psa[i + 1][j + 1] = psa[i + 1][j] + psa[i][j + 1] - psa[i][j] + (ch == '#');
        }
    }
    
    q.emplace(0, 0);
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second; q.pop();
        for (auto d : dir) {
            int nr = cr + d.first, nc = cc + d.second;
            if (nr >= 0 && nr + L <= R && nc >= 0 && nc + W <= C && open(nr, nc, nr + L - 1, nc + W - 1) && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[cr][cc] + 1;
                q.emplace(nr, nc);
            }
        }
    }
    
    cout << (open(0, 0, L - 1, W - 1) ? dist[R - L][C - W] : -1) << '\n';
    return 0;
}
