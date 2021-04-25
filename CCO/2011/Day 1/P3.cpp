#include <bits/stdc++.h>

using namespace std;

bitset<2001> adj[2][2001];

bool solve(int N, int type) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((adj[type][i] & adj[type][j]).count() > 1) return false;
        }
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, K, i, j;
    cin >> N >> M >> K;
    
    while (K--) {
        cin >> i >> j;
        adj[0][i][j] = adj[1][j][i] = true;
    }
    
    cout << (solve(N, 0) && solve(N, 1) ? "YES" : "NO") << '\n';
    return 0;
}
