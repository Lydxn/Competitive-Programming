#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1025;
int BIT[MAXN][MAXN];

void update(int X, int Y, int A)
{
    for (int i = X; i < MAXN; i += i & -i)
    {
        for (int j = Y; j < MAXN; j += j & -j)
        {
            BIT[i][j] += A;
        }
    }
}

int query(int X, int Y)
{
    int sum = 0;
    for (int i = X; i > 0; i -= i & -i)
    {
        for (int j = Y; j > 0; j -= j & -j)
        {
            sum += BIT[i][j];
        }
    }
    return sum;
}

int query(int L, int B, int R, int T)
{
    return query(R, T) - query(R, B - 1) - query(L - 1, T) + query(L - 1, B - 1);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int op, S, X, Y, A, L, B, R, T;
    
    while (true)
    {
        cin >> op;
        switch (op)
        {
            case 0:
                cin >> S;
                break;
            case 1:
                cin >> X >> Y >> A;
                update(X + 1, Y + 1, A);
                break;
            case 2:
                cin >> L >> B >> R >> T;
                cout << query(L + 1, B + 1, R + 1, T + 1) << '\n';
                break;
            case 3:
                return 0;
        }
    }
}
