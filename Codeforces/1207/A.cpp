#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, b, p, f, h, c, profit;
    cin >> t;
    
    while (t--)
    {
        cin >> b >> p >> f >> h >> c;
        
        if (h < c) swap(h, c), swap(p, f);
        profit = 0;
        
        profit += h * min(b / 2, p), b -= 2 * min(b / 2, p);
        profit += c * min(b / 2, f), b -= 2 * min(b / 2, f);
        
        cout << profit << '\n';
    }
    return 0;
}
