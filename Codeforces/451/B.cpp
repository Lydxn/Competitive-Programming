#include <bits/stdc++.h>

using namespace std;

int a[100000], sorted[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p1 = 0, p2 = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted, sorted + n);
    
    for (int i = 0; i < n; i++)
    {
        if (sorted[i] != a[i])
        {
            p1 = i;
            break;
        }
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (sorted[i] != a[i])
        {
            p2 = i;
            break;
        }
    }

    for (int i = p1, j = p2; i <= p2; i++, j--)
    {
        if (sorted[i] != a[j])
        {
            cout << "no\n";
            return 0;
        }
    }
    
    cout << "yes\n" << p1 + 1 << ' ' << p2 + 1 << '\n';
    return 0;
}
