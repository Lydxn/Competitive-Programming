#include <iostream>

using namespace std;

const int MAXN = 300001;
int g[MAXN], BIT[21][MAXN], N, M, op, a, b, c, sum;

int query(int x, int b)
{
    int sum = 0;
    for (; x > 0; x -= x & -x) sum += BIT[b][x];
    return sum;
}


int query_range(int l, int r, int b)
{
    return query(r, b) - query(l - 1, b);
}

void update(int x, int v, int b)
{
    for (; x <= N; x += x & -x) BIT[b][x] += v;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> g[i];
        update(i, 1, g[i]);
    }

    while (M--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            update(a, -1, g[a]);
            update(a, 1, g[a] = b);
        }
        else
        {
            cin >> a >> b >> c;

            sum = 0;
            for (int i = 20; i >= 0; i--)
            {
                sum += query_range(a, b, i);
                if (sum >= c)
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
