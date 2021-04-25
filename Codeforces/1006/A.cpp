#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;
    cin >> n;
    
    while (n--)
    {
        cin >> a;
        cout << a - (a % 2 == 0) << ' ';
    }
    return 0;
}
