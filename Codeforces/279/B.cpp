#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, t, max_books = 0, sum = 0;
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int l = 0, r = 0; r < n; r++)
    {
        for (sum += a[r]; l <= r && sum > t; l++) sum -= a[l];
        max_books = max(max_books, r - l + 1);
    }
    
    cout << max_books << '\n';
    return 0;
}
