#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, len = 1, max_len = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i]) ++len;
        else len = 1;
        max_len = max(max_len, len);
    }
    
    cout << max_len << '\n';
    return 0;
}
