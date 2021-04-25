#include <algorithm>
#include <iostream>

using namespace std;

int numbers[15][15];

int max_total(int N, int x, int y)
{
    return numbers[x][y] + (x == N - 1 ? 0 : max(max_total(N, x + 1, y), max_total(N, x + 1, y + 1)));
}

int main()
{
    int T, N;
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++) cin >> numbers[i][j];
        }
        cout << max_total(N, 0, 0) << '\n';
    }
    return 0;
}
