#include <bits/stdc++.h>

using namespace std;

int a[400000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, max_rest = 0, curr = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a[n + i] = a[i];
    
    for (int i : a)
    {
        if (i == 1) ++curr;
        else        curr = 0;
        max_rest = max(max_rest, curr);
    }
    
    cout << max_rest << '\n';
    return 0;
}
