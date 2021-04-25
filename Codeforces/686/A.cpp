#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    long long sum = x;
    int d, distressed = 0;
    char ch;

    while (n--)
    {
        cin >> ch >> d;
        if (ch == '+') sum += d;
        else if (ch == '-')
        {
            if (sum >= d) sum -= d;
            else         ++distressed;
        }
    }
    
    cout << sum << ' ' << distressed << '\n';
    return 0;
}
