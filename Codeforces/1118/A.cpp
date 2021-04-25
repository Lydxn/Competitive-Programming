#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int q, a, b;
    long long n;
    cin >> q;
    
    while (q--)
    {
        cin >> n >> a >> b;
        cout << (n / 2) * min(2 * a, b) + a * (n % 2) << '\n';
    }
    return 0;
}
