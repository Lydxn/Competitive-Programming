#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int diff[30001][1000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int M, N, K, x, y, R, B, maxx = 0, num = 0;
    cin >> M >> N >> K;
    
    while (K--) {
        cin >> x >> y >> R >> B; --x, --y;
        for (int i = max(0, x - R); i <= min(x + R, N - 1); i++) {
            int range = sqrt(R * R - (x - i) * (x - i));
            diff[max(0, y - range)][i] += B, diff[min(y + range + 1, M)][i] -= B;
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i) diff[i][j] += diff[i - 1][j];
            if (maxx == diff[i][j]) ++num;
            if (maxx < diff[i][j]) maxx = diff[i][j], num = 1;
        }
    }
    
    cout << maxx << '\n' << num << '\n';
    return 0;
}
