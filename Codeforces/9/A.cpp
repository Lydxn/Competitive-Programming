#include <bits/stdc++.h>

using namespace std;

string lookup[7] = {"", "1/1", "5/6", "2/3", "1/2", "1/3", "1/6"};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int Y, W;
    cin >> Y >> W;
    
    cout << lookup[max(Y, W)] << '\n';
    return 0;
}
