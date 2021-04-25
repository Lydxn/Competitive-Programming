#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int count = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0) ++count;
    }
    
    cout << count << '\n';
    return 0;
}
