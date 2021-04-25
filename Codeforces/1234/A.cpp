#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int q, n, a, sum;
    cin >> q;
    
    while (q--)
    {
        cin >> n;
        
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
        }
        
        cout << (int) ceil((double) sum / n) << '\n';
    }
    return 0;
}
