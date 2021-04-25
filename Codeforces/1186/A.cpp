#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    cout << (n <= m && n <= k ? "Yes" : "No") << '\n';
    return 0;
}
