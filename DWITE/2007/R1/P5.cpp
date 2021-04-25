#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char grid[10][10];
int dist[10][10];
queue<pii> q;
pii parent[10][10], dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<pii> get_path(pii v)
{
    vector<pii> res;
    for (; v.first != -1; v = parent[v.first][v.second]) res.push_back(v);
    return res;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int R, C, hr, hc, vr, vc, er, ec;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'H')      hr = i, hc = j;
            else if (grid[i][j] == 'V') vr = i, vc = j;
            else if (grid[i][j] == 'E') er = i, ec = j;
        }
    }

    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) dist[i][j] = INT_MAX;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) parent[i][j] = {-1, -1};
    dist[er][ec] = 0;
    q.emplace(er, ec);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (const auto& i : dir)
        {
            int r = curr.first + i.first, c = curr.second + i.second, d = dist[curr.first][curr.second] + 1;
            if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] != '#' && d < dist[r][c])
            {
                parent[r][c] = curr;
                dist[r][c] = d;
                q.emplace(r, c);
            }
        }
    }

    auto hpath = get_path({hr, hc}), vpath = get_path({vr, vc});
    while (vpath.size() < 2 * hpath.size()) vpath.emplace_back(er, ec);

    int steps = 0;
    for (int i = 0, j = 0; i < hpath.size(); i++, j += 2, steps++)
    {
        if (hpath[i].first == er && hpath[i].second == ec && !(vpath[i].first == er && vpath[i].second == ec))
        {
            cout << "escape\n";
            return 0;
        }

        if ((hpath[i].first == vpath[j].first && hpath[i].second == vpath[j].second) ||
            (hpath[i].first == vpath[j - 1].first && hpath[i].second == vpath[j - 1].second))
        {
            cout << steps << '\n';
            return 0;
        }
    }
}
