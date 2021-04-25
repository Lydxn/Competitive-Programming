#include <bits/stdc++.h>

using namespace std;

struct point
{
    int r, c, d;
    point(int r, int c, int d) : r(r), c(c), d(d) {}
};

pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char grid[50][50];
int flood[50][50];
bool visited[50][50];
queue<point> q;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int R, C, sr, sc, dr, dc;
    cin >> R >> C;
    
    memset(flood, 0x3f, sizeof(flood));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') sr = i, sc = j;
            if (grid[i][j] == 'D') dr = i, dc = j;
            if (grid[i][j] == '*') q.emplace(i, j, 0), flood[i][j] = 0;
        }
    }

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        
        for (const auto& i : dir)
        {
            int nr = curr.r + i.first, nc = curr.c + i.second, nd = curr.d + 1;
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != 'X' && grid[nr][nc] != 'D' && nd < flood[nr][nc])
            {
                flood[nr][nc] = nd;
                q.emplace(nr, nc, nd);
            }
        }
    }

    queue<point>().swap(q);
    q.emplace(sr, sc, 0);
    
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        
        if (grid[curr.r][curr.c] == 'D')
        {
            cout << curr.d << '\n';
            return 0;
        }
        
        for (const auto& i : dir)
        {
            int nr = curr.r + i.first, nc = curr.c + i.second, nd = curr.d + 1;
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != 'X' && grid[nr][nc] != '*' && !visited[nr][nc] && nd < flood[nr][nc])
            {
                visited[nr][nc] = true;
                q.emplace(nr, nc, nd);
            }
        }
    }
    
    cout << "KAKTUS\n";
    return 0;
}
