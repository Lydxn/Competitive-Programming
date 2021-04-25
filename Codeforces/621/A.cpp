#include <bits/stdc++.h>

using namespace std;

int nums[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    
    if (sum % 2)
    {
        sort(nums, nums + n);
        for (int i : nums)
        {
            if (i % 2)
            {
                sum -= i;
                break;
            }
        }
    }
    
    cout << sum << '\n';
    return 0;
}
