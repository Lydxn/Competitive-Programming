#include <bits/stdc++.h>

using namespace std;

int pre[150001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, h;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h;
        pre[i] = h + pre[i - 1];
    }
    
    int min_sum = INT_MAX, min_idx, sum;
    for (int i = 0; i <= n - k; i++)
    {
        sum = pre[i + k] - pre[i];
        if (sum < min_sum)
        {
            min_sum = sum;
            min_idx = i;
        }
    }
    
    cout << min_idx + 1 << '\n';
    return 0;
}
