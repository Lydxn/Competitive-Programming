#include <bits/stdc++.h>

#define dist(x1, x2, y1, y2) ((x2) - (x1)) * ((x2) - (x1)) + ((y2) - (y1)) * ((y2) - (y1))

using namespace std;

struct point
{
    int x, i, c;
    bool operator < (const point& p) const
    {
        return x < p.x;
    }
};

point points[200001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, x, y, c;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> x >> y >> c;
        points[i] = {x, i, c};
    }

    sort(points + 1, points + N + 1);
    for (int i = 1; i <= N - 2; i++)
    {
        if (!(points[i].c == points[i + 1].c && points[i + 1].c == points[i + 2].c))
        {
            cout << points[i].i << ' ' << points[i + 1].i << ' ' << points[i + 2].i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}
