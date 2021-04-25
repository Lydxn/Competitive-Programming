#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, zeros = 0, ones = 0;
    string s;
    cin >> n >> s;
    
    for (int i = 0; i < n; i++)
    {
        zeros += s[i] == 'z';
        ones += s[i] == 'n';
    }
    
    while (ones--) cout << "1 ";
    while (zeros--) cout << "0 ";
    return 0;
}
