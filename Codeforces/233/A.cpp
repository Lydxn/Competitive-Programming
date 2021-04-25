#include <bits/stdc++.h>

using namespace std;

int p[100];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    if (n % 2) cout << -1 << '\n';
    else
    {
        for (int i = 0; i < n; i++) p[i] = i + 1;
        for (int i = 1; i < n; i += 2) swap(p[i], p[i - 1]);
        for (int i = 0; i < n; i++) cout << p[i] << ' ';
    }
    return 0;
}
