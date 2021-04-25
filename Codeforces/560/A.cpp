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
        if (a == 1)
        {
            cout << "-1\n";
            return 0;
        }
    }
    
    cout << "1\n";
    return 0;
}
