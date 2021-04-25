#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n % 3 == 2) cout << "1 2 " << n - 3 << '\n';
    else            cout << "1 1 " << n - 2 << '\n';
    return 0;
}
