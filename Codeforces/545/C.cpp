#include <bits/stdc++.h>

using namespace std;

int x[100000], h[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 2;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> h[i];

    for (int i = 1; i < n - 1; i++)
    {
        if (x[i - 1] < x[i] - h[i]) ++ans;
        else if (h[i] + x[i] < x[i + 1]) x[i] += h[i], ++ans;
    }
    
    cout << (n == 1 ? 1 : ans) << '\n';
    return 0;
}
