#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int P, Y;
ll T;

bool solve(ll n)
{
    ll res = 0;
    for (int i = 0; i < Y; i++)
    {
        res += n;
        res += (ll) (res * (P / 100.0));
        if (res >= T) return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    
    ll l = 0, r = 1e17, m;
    cin >> P >> Y >> T;

    while (l < r)
    {
        m = (l + r) / 2;
        if (solve(m)) r = m;
        else          l = m + 1;
    }
    
    cout << l << '\n';
    return 0;
}
