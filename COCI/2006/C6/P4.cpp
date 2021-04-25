// not actually completed... gives 6/10 TLE

#include <bits/stdc++.h>

using namespace std;

char grid[30000][30];
int R, C;

void drop(int col)
{
    int r = -1, c = col;
    while (true)
    {
        if (grid[r + 1][c] == '.') ++r;
        else if (r == R - 1 || grid[r + 1][c] == 'X') break;
        else if (r < R - 1 && c > 0 && grid[r + 1][c] == 'O' && grid[r][c - 1] == '.' && grid[r + 1][c - 1] == '.') --c;
        else if (r < R - 1 && c < C - 1 && grid[r + 1][c] == 'O' && grid[r][c + 1] == '.' && grid[r + 1][c + 1] == '.') ++c;
        else break;
    }
    
    if (r != -1) grid[r][c] = 'O';
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, col;
    cin >> R >> C;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++) cin >> grid[i][j];
    }
    
    cin >> N;
    while (N--)
    {
        cin >> col;
        drop(col - 1);
    }
    
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++) cout << grid[i][j];
        cout << '\n';
    }
    return 0;
}
