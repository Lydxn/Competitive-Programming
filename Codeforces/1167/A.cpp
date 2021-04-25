#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, n, first8;
    string s;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> s;
        
        first8 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '8')
            {
                first8 = i;
                break;
            }
        }
        cout << (n - first8 >= 11 ? "YES" : "NO") << '\n';
    }
    return 0;
}
