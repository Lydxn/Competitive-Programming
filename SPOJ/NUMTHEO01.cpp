#include <iostream>

using namespace std;

typedef long long ll;

ll fact_mod(int n, ll x)
{
    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * i % x;
    }
    return res;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    ll x;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> x;
        cout << fact_mod(n, x) << '\n';
    }
    
    return 0;
}
