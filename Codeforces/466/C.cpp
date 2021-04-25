#include <bits/stdc++.h>

using namespace std;

int a[500000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long ways = 0, sum = 0, pre_sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            pre_sum += a[i];
            if (pre_sum == 2 * sum / 3) ways += cnt;
            if (pre_sum == sum / 3)     ++cnt;
        }
    }
    
    cout << ways << '\n';
    return 0;
}
