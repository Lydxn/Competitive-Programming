#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, num25 = 0, num50 = 0;
    cin >> n;
    
    while (n--)
    {
        cin >> k;

        if (k == 25) num25++;
        else if (k == 50)
        {
            if (num25 >= 1) num25--, num50++;
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
        else if (k == 100)
        {
            if (num25 >= 1 && num50 >= 1) num25--, num50--;
            else if (num25 >= 3 && num50 == 0) num25 -= 3;
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    
    cout << "YES\n";
    return 0;
}
