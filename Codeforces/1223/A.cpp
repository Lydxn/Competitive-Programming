#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int q, n;
    cin >> q;
    
    while (q--)
    {
        cin >> n;
        cout << (n == 2 ? 2 : n % 2) << '\n';
    }
    return 0;
}
