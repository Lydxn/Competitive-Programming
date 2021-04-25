#include <bits/stdc++.h>

using namespace std;

int X[1001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, A, B, C, Y;
    cin >> N >> M >> A >> B >> C;
    
    for (int i = 1; i <= N; i++) cin >> X[i];
    
    while (C--)
    {
        cin >> Y;
        if (X[Y] == 1) M += A;
        else M -= B;
    }
    
    cout << M << '\n';
    return 0;
}
