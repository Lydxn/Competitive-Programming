#include <bits/stdc++.h>

using namespace std;

int a[100000];
vector<int> steps;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    
    for (int i = 2; i < n; i++)
    {
        if (a[i - 2] + a[i - 1] > a[i])
        {
            cout << "YES\n";
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}
