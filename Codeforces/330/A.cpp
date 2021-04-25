#include <bits/stdc++.h>

using namespace std;

bool row[10], col[10];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int r, c, count = 0;
    cin >> r >> c;
    
    char cell;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> cell;
            if (cell == 'S') row[i] = col[j] = true;
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!row[i] || !col[j]) ++count;
        }
    }
    
    cout << count << '\n';
    return 0;
}
