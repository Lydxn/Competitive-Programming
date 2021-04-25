#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int mat[1500][1500], dp[1500][1500], N;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int solve(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    int res = 0;
    for (auto d : dir) {
        int ni = i + d.first, nj = j + d.second;
        if (ni >= 0 && ni < N && nj >= 0 && nj < N && mat[i][j] < mat[ni][nj]) {
            res = max(res, solve(ni, nj) + 1);
        }
    }
    return dp[i][j] = res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = max(ans, solve(i, j));
        }
    }

    cout << ans << '\n';
    return 0;
}
