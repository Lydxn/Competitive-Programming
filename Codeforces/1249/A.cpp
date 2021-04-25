#include <bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int q, n;
    cin >> q;
    
    while (q--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ok &= abs(a[i] - a[j]) != 1;
            }
        }
        cout << 2 - ok << '\n';
    }
    return 0;
}
