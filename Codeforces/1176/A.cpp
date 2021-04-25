#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int q, cnt2, cnt3, cnt5;
    cin >> q;
    
    long long n;
    while (q--)
    {
        cin >> n;
        
        cnt2 = cnt3 = cnt5 = 0;
        while (n % 2 == 0) n /= 2, ++cnt2;
        while (n % 3 == 0) n /= 3, ++cnt3;
        while (n % 5 == 0) n /= 5, ++cnt5;
        
        cout << (n == 1 ? cnt2 + 2 * cnt3 + 3 * cnt5 : -1) << '\n';
    }
    return 0;
}
