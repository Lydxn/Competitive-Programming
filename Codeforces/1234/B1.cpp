#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, id;
    cin >> n >> k;
    
    deque<int> ids;
    while (n--)
    {
        cin >> id;
        if (find(ids.begin(), ids.end(), id) == ids.end())
        {
            if (int(ids.size()) >= k) ids.pop_back();
            ids.push_front(id);
        }
    }
    
    cout << ids.size() << '\n';
    for (int i : ids) cout << i << ' ';
    return 0;
}
