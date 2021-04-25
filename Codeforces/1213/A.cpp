#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, odd = 0, even = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2) ++odd;
        else       ++even;
    }
    
    cout << min(odd, even) << '\n';
    return 0;
}
