#include <bits/stdc++.h>

using namespace std;

int a[92];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (a[n - 1] == 0)            cout << "UP\n";
    else if (a[n - 1] == 15)      cout << "DOWN\n";
    else if (n == 1)              cout << -1 << '\n';
    else if (a[n - 1] > a[n - 2]) cout << "UP\n";
    else                          cout << "DOWN\n";
    return 0;
}
