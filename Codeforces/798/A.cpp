#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int change = 0, len = s.size();
    for (int i = 0; i < len / 2; i++) change += s[i] != s[len - i - 1];
    
    cout << ((change == 0 && len % 2) || change == 1 ? "YES" : "NO") << '\n';
    return 0;
}
