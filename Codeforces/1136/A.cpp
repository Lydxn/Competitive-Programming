#include <bits/stdc++.h>

using namespace std;

pair<int, int> book[100];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> book[i].first >> book[i].second;
    cin >> k;
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (k >= book[i].first)
        {
            cout << n - i << '\n';
            return 0;
        }
    }
}
