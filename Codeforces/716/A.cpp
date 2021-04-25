#include <bits/stdc++.h>

using namespace std;

int t[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> t[i];
    
    int words = 1;
    for (int i = n - 1; t[i] - t[i - 1] <= c && i--; words++);
    
    cout << words << '\n';
    return 0;
}
