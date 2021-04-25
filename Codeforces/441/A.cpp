#include <bits/stdc++.h>

using namespace std;

vector<int> q;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, v, k, s;
    cin >> n >> v;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        
        bool flag = true;
        while (k--)
        {
            cin >> s;
            if (flag && v > s)
            {
                q.push_back(i);
                flag = false;
            }
        }
    }
    
    cout << q.size() << '\n';
    for (int i : q) cout << i << ' ';
    return 0;
}
