#include <bits/stdc++.h>

using namespace std;

char grid[2000][2000];
int N, M;

void dfs(int i, int j) {
    switch (grid[i][j]) {
        case 'N':
            for (int k = i - 1; k >= 0; k--) if (grid[k][j] != '.') dfs(k, j);
            break;
        case 'E':
            for (int k = j + 1; k < M; k++)  if (grid[i][k] != '.') dfs(i, k);
            break;
        case 'S':
            for (int k = i + 1; k < N; k++)  if (grid[k][j] != '.') dfs(k, j);
            break;
        case 'W':
            for (int k = j - 1; k >= 0; k--) if (grid[i][k] != '.') dfs(i, k);
            break;
    }
    
    grid[i][j] = '.';
    cout << '(' << i << ',' << j << ")\n";
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '.') dfs(i, j);
        }
    }
    return 0;
}
