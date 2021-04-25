#include <bits/stdc++.h>

using namespace std;

int x[4];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> x[0] >> x[1] >> x[2] >> x[3];

    sort(x, x + 4);
    cout << x[3] - x[0] << ' ' << x[3] - x[1] << ' ' << x[3] - x[2] << '\n';
    return 0;
}
