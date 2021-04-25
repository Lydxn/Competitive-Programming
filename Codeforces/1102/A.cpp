#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    cout << (long long) n * (n + 1) / 2 % 2 << '\n';
    return 0;
}
