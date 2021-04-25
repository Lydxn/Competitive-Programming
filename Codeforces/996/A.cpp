#include <bits/stdc++.h>

using namespace std;

int denom[] = {100, 20, 10, 5, 1};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, bills = 0;
    cin >> n;

    for (int i = 0; i < 5; i++)
    {
        int amount = n / denom[i];
        if (amount)
        {
            bills += amount;
            n -= amount * denom[i];
        }
    }
    
    cout << bills << '\n';
    return 0;
}
