#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, width;
    cin >> n;
    
    for (int i = 0; i < 2 * n + 1; i++)
    {
        width = i <= n ? i : 2 * n - i;
        for (int j = 0; j < n - width; j++)     cout << "  ";
        for (int j = 0; j < 2 * width + 1; j++) cout << (j <= width ? j : 2 * width - j) << (j < 2 * width ? ' ' : '\n');
    }
    return 0;
}
