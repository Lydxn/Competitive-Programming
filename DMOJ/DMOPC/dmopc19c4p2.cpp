// messiest solution i've ever done

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int r1, c1, r2, c2;
    bool sq;

    node(int r1, int c1, int r2, int c2, bool sq) : r1(r1), c1(c1), r2(r2), c2(c2), sq(sq) {}
};

int N, rs, cs, re, ce, r1, c1, r2, c2, dist[16][16][16][16][2];

void bfs()
{
    queue<node> q;
    q.emplace(r1, c1, r2, c2, rs == r1 && cs == c1);
    memset(dist, INF, sizeof(dist));
    dist[r1][c1][r2][c2][rs == r1 && cs == c1] = 0;

    while (!q.empty())
    {
        node curr = q.front();
        q.pop();

        if ((curr.r1 == re && curr.c1 == ce && curr.sq) || (curr.r2 == re && curr.c2 == ce && !curr.sq))
        {
            cout << dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] << '\n';
            return;
        }

        if (!curr.sq)
        {
            if (curr.r1 + 1 <= N && !(curr.r1 + 1 == curr.r2 && curr.c1 == curr.c2) && dist[curr.r1 + 1][curr.c1][curr.r2][curr.c2][curr.sq] == INF)
            {
                dist[curr.r1 + 1][curr.c1][curr.r2][curr.c2][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1 + 1, curr.c1, curr.r2, curr.c2, curr.sq);
            }

            if (curr.r1 - 1 >= 1 && !(curr.r1 - 1 == curr.r2 && curr.c1 == curr.c2) && dist[curr.r1 - 1][curr.c1][curr.r2][curr.c2][curr.sq] == INF)
            {
                dist[curr.r1 - 1][curr.c1][curr.r2][curr.c2][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1 - 1, curr.c1, curr.r2, curr.c2, curr.sq);
            }

            if (curr.c1 + 1 <= N && !(curr.r1 == curr.r2 && curr.c1 + 1 == curr.c2) && dist[curr.r1][curr.c1 + 1][curr.r2][curr.c2][curr.sq] == INF)
            {
                dist[curr.r1][curr.c1 + 1][curr.r2][curr.c2][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1, curr.c1 + 1, curr.r2, curr.c2, curr.sq);
            }

            if (curr.c1 - 1 >= 1 && !(curr.r1 == curr.r2 && curr.c1 - 1 == curr.c2) && dist[curr.r1][curr.c1 - 1][curr.r2][curr.c2][curr.sq] == INF)
            {
                dist[curr.r1][curr.c1 - 1][curr.r2][curr.c2][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1, curr.c1 - 1, curr.r2, curr.c2, curr.sq);
            }
        }

        if (curr.sq)
        {
            if (curr.r2 + 1 <= N && !(curr.r2 + 1 == curr.r1 && curr.c2 == curr.c1) && dist[curr.r1][curr.c1][curr.r2 + 1][curr.c2][curr.sq] == INF)
            {

                dist[curr.r1][curr.c1][curr.r2 + 1][curr.c2][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1, curr.c1, curr.r2 + 1, curr.c2, curr.sq);
            }

            if (curr.r2 - 1 >= 1 && !(curr.r2 - 1  == curr.r1 && curr.c2 == curr.c1) && dist[curr.r1][curr.c1][curr.r2 - 1][curr.c2][curr.sq] == INF)
            {
                dist[curr.r1][curr.c1][curr.r2 - 1][curr.c2][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1, curr.c1, curr.r2 - 1, curr.c2, curr.sq);
            }

            if (curr.c2 + 1 <= N && !(curr.r2 == curr.r1 && curr.c2 + 1 == curr.c1) && dist[curr.r1][curr.c1][curr.r2][curr.c2 + 1][curr.sq] == INF)
            {
                dist[curr.r1][curr.c1][curr.r2][curr.c2 + 1][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1, curr.c1, curr.r2, curr.c2 + 1, curr.sq);
            }

            if (curr.c2 - 1 >= 1 && !(curr.r2 == curr.r1 && curr.c2 - 1 == curr.c1) && dist[curr.r1][curr.c1][curr.r2][curr.c2 - 1][curr.sq] == INF)
            {
                dist[curr.r1][curr.c1][curr.r2][curr.c2 - 1][curr.sq] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
                q.emplace(curr.r1, curr.c1, curr.r2, curr.c2 - 1, curr.sq);
            }
        }

        if (((curr.r1 + 1 == curr.r2 && curr.c1 == curr.c2) ||
             (curr.r1 - 1 == curr.r2 && curr.c1 == curr.c2) ||
             (curr.r1 == curr.r2 && curr.c1 + 1 == curr.c2) ||
            ( curr.r1 == curr.r2 && curr.c1 - 1 == curr.c2)) && dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq ^ 1] == INF)
        {
            dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq ^ 1] = dist[curr.r1][curr.c1][curr.r2][curr.c2][curr.sq] + 1;
            q.emplace(curr.r1, curr.c1, curr.r2, curr.c2, curr.sq ^ 1);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> rs >> cs >> re >> ce >> r1 >> c1 >> r2 >> c2;

    bfs();
    return 0;
}
