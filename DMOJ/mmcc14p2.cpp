#include <bits/stdc++.h>

using namespace std;

long long grid[2001][5001];
int row[2001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, Q, L, R; char ch;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        row[i] = i;
        for (int j = 1; j <= M; j++) {
            cin >> ch;
            grid[i][j] = (grid[i][j - 1] * 131 + ch) % 1000000007;
        }
    }
    
    cin >> Q;
    while (Q--) {
        cin >> L >> R;
        int lo = 0, hi = M, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            for (int i = L; i <= R; i++) {
                if (grid[row[L]][mid] != grid[row[i]][mid]) {
                    hi = mid - 1;
                    goto next;
                }
            }
            lo = mid; next:;
        }
        
        cout << (R - L + 1) * lo << '\n';
        swap(row[L], row[R]);
    }
    return 0;
}
