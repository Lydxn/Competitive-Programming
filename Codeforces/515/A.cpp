#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, s, sum;
    cin >> a >> b >> s;
    
    sum = abs(a) + abs(b);
    cout << (sum <= s && sum % 2 == s % 2 ? "Yes" : "No") << '\n';
    return 0;
}
