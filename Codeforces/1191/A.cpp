#include <bits/stdc++.h>

using namespace std;

unordered_map<int, string> ans = {{0, "1 A"}, {1, "0 A"}, {2, "1 B"}, {3, "2 A"}};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int x;
    cin >> x;
    
    cout << ans[x % 4] << '\n';
    return 0;
}
