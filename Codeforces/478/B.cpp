#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pairs(ll n)
{
    return n * (n - 1) / 2;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    ll kmin = (m - n % m) * pairs(n / m) + (n % m) * pairs(n / m + 1), kmax = pairs(n - m + 1); 
    cout << kmin << ' ' << kmax << '\n';
    return 0;
}
