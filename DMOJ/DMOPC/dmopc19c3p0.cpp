#include <bits/stdc++.h>

using namespace std;

int a[10];

bool is_arith()
{
    for (int i = 0; i < 8; i++)
    {
        if (a[i] + a[i + 2] != 2 * a[i + 1]) return false;
    }
    return true;
}

bool is_geom()
{
    double prog = (double) a[1] / a[0];
    for (int i = 0; i < 8; i++)
    {
        if (a[i] * a[i + 2] != a[i + 1] * a[i + 1]) return false;
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--)
    {
        for (int i = 0; i < 10; i++) cin >> a[i];
        bool ari = is_arith(), geo = is_geom();

        if (ari && geo) cout << "both\n";
        else if (ari) cout << "arithmetic\n";
        else if (geo) cout << "geometric\n";
        else cout << "neither\n";
    }
    return 0;
}
