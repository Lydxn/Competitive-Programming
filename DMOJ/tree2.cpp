#include <bits/stdc++.h>

using namespace std;

struct node {
    int r, c, cnt, dist;
    node(int r, int c, int cnt, int dist) : r(r), c(c), cnt(cnt), dist(dist) {}
    bool operator < (const node& p) const {
        return dist == p.dist ? cnt > p.cnt : dist > p.dist;
    }
};

int grid[10][10], cnt[10][10], dist[10][10];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
priority_queue<node> pq;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int R, C, sr, sc, er, ec, max_h = 0, max_dist = INT_MAX; char ch;
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ch;
            if (ch == 'X') sr = i, sc = j;
            else if (ch != '.') max_h = max(max_h, grid[i][j] = ch - '0');
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int d = (sr - i) * (sr - i) + (sc - j) * (sc - j);
            if (grid[i][j] == max_h && d < max_dist) max_dist = d, er = i, ec = j;
        }
    }
    
    memset(cnt, 0x3f, sizeof(cnt)); memset(dist, 0x3f, sizeof(dist));
    cnt[sr][sc] = dist[sr][sc] = 0;
    pq.emplace(sr, sc, 0, 0);
    
    while (!pq.empty()) {
        node curr = pq.top(); pq.pop();
        if (curr.dist > dist[curr.r][curr.c]) continue;
        
        for (auto d : dir) {
            int nr = curr.r + d.first, nc = curr.c + d.second, ncnt = curr.cnt + !!grid[nr][nc], ndist = curr.dist + grid[nr][nc];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && (ndist < dist[nr][nc] || (ndist == dist[nr][nc] && ncnt < cnt[nr][nc]))) {
                cnt[nr][nc] = ncnt, dist[nr][nc] = ndist;
                pq.emplace(nr, nc, ncnt, ndist);
            }
        }
    }
    
    cout << cnt[er][ec] - 1 << '\n';
    return 0;
}
