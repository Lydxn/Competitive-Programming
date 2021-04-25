#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    
    for (int i = 1, idx = 0; idx < n; i++, idx += i) putchar(s[idx]);
    return 0;
}
