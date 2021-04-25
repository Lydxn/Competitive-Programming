#include <bits/stdc++.h>

using namespace std;

int N, A[1001], B[1001], dp[1001][1001];
char S[1001], T[1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
             dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + ((S[i] == 'W' && T[j] == 'L' && A[i] > B[j]) || (S[i] == 'L' && T[j] == 'W' && A[i] < B[j]) ? A[i] + B[j] : 0)));
        }
    }
    
    cout << dp[N][N] << '\n';
    return 0;
}
