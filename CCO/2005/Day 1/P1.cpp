#include <bits/stdc++.h>

using namespace std;

int N, M, mat[100][100];
queue<pair<int, int>> q;
bool visited[100][100];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool path(int i, int j, int k) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>>().swap(q);
    for (int i = 0; i < N; i++) q.emplace(0, i), visited[0][i] = true;
    
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second; q.pop();
        if (cr == M - 1) return true;
        
        for (auto d : dir) {
            int nr = cr + d.first, nc = cc + d.second;
            if (nr >= 0 && nr < M && nc >= 0 && nc < N && !visited[nr][nc] && (mat[nr][nc] == i || mat[nr][nc] == j || mat[nr][nc] == k)) {
                q.emplace(nr, nc);
                visited[nr][nc] = true;
            }
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (path(i, j, k)) {
                    cout << i << ' ' << j << ' ' << k << '\n';
                    return 0;
                }
            }
        }
    }
    
    cout << "-1 -1 -1\n";
    return 0;
}
