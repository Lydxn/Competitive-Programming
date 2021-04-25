#include <bits/stdc++.h>

using namespace std;

const int CACHE_SZ = 1594324;
int R, C, board[13][13], err[2];
double dp[CACHE_SZ][2];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

double solve(int board[13][13], int turn) {
    int hashed = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            hashed = hashed * 3 + board[i][j];
        }
    }
    
    if (dp[hashed][turn] != -1) return dp[hashed][turn];
    else {
        vector<double> proposal;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == turn + 1) {
                    for (auto d : dir) {
                        int nr = r + d.first, nc = c + d.second;
                        if (nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc]) {
                            int temp = board[nr][nc];
                            board[nr][nc] = board[r][c], board[r][c] = 0;
                            proposal.push_back(1 - solve(board, turn ^ 1));
                            board[r][c] = board[nr][nc], board[nr][nc] = temp;
                        }
                    }
                }
            }
        }
        
        sort(proposal.begin(), proposal.end(), greater<double>());
        int sz = min(int(proposal.size()), err[turn]); double res = 0;
        for (int i = 0; i < sz; i++) res += proposal[i];
        return dp[hashed][turn] = sz ? res / sz : 0;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    char ch;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ch;
            board[i][j] = ch == 'J' ? 1 : 2;
        }
    }
    
    cin >> err[0] >> err[1];
    for (int i = 0; i < CACHE_SZ; i++) dp[i][0] = dp[i][1] = -1;
    
    cout << fixed << setprecision(3) << solve(board, 0) << '\n';
    return 0;
}
