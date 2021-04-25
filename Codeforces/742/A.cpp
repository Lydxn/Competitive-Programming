#include <bits/stdc++.h>

using namespace std;

int lookup[] = {8, 4, 2, 6};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    cout << (n ? lookup[(n - 1) % 4] : 1) << '\n';
    return 0;
}
