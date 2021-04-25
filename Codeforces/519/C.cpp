#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    cout << min((n + m) / 3, min(n, m)) << '\n';
    return 0;
}
