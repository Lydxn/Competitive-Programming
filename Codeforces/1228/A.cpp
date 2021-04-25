#include <bits/stdc++.h>

using namespace std;

int seen[10];

bool unique_digits(int x)
{
    memset(seen, 0, sizeof(seen));
    while (x)
    {
        ++seen[x % 10];
        x /= 10;
    }
    
    for (int s : seen) if (s > 1) return false;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int l, r, x = -1;
    cin >> l >> r;
    
    for (int i = l; i <= r; i++)
    {
        if (unique_digits(i))
        {
            x = i;
            break;
        }
    }
    
    cout << x << '\n';
    return 0;
}
