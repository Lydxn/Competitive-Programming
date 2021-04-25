#include <bits/stdc++.h>

using namespace std;

int a[100000], distinct[100000];
unordered_set<int> s;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, l;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = n - 1; i >= 0; i--)
    {
        s.insert(a[i]);
        distinct[i] = s.size();
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> l;
        cout << distinct[l - 1] << '\n'; 
    }
    return 0;
}
