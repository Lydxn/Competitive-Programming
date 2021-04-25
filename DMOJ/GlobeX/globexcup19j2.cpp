#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M, A, B;
ll X[6][10], ans = INT_MIN;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> A >> B;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> X[i][j];
        }
    }
    
    int K = min(N / A, M / B);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    for (int m = 0; m < 10; m++)
                    {
                        for (int n = 0; n < 10; n++)
                        {
                            if (i + j + k + l + m + n <= K) ans = max(ans, X[0][i] + X[1][j] + X[2][k] + X[3][l] + X[4][m] + X[5][n]);
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
