#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, count = 0;
    cin >> n >> m;

    for (int a = 0; a <= min(n, m); a++)
    {
        for (int b = 0; b <= min(n, m); b++)
        {
            if (a * a + b == n && a + b * b == m) ++count;
        }
    }
    
    cout << count << '\n';
    return 0;
}
