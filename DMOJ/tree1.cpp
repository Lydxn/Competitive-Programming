#include <bits/stdc++.h>

using namespace std;

int mat[4][4], edges, vis;

void dfs(int curr) {
    if (vis & (1 << curr)) return;
    vis |= 1 << curr;
    
    for (int i = 0; i < 4; i++) {
        if (mat[curr][i]) {
            dfs(i);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[i][j];
            edges += mat[i][j];
        }
    }
    
    dfs(0);
    cout << (edges == 6 && vis == 15 ? "Yes" : "No") << '\n';
    return 0;
}
