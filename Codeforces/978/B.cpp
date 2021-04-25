#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, xxx = 0;
    string file;
    cin >> n >> file;
    
    for (int i = 0; i < n - 2; i++)
    {
        if (file.substr(i, 3) == "xxx") ++xxx;
    }
    
    cout << xxx << '\n';
    return 0;
}
