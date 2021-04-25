#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;
    
    cout << (n / k % 2 ? "YES" : "NO") << '\n';
    return 0;
}
