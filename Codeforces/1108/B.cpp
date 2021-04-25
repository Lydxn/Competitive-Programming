#include <bits/stdc++.h>

using namespace std;

multiset<int> divisors;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, d, x, y;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        divisors.insert(d);
    }
    
    x = *divisors.rbegin();
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0) divisors.erase(divisors.find(i));
    }
    y = *divisors.rbegin();
    
    cout << x << ' ' << y << '\n';
    return 0;
}
