#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string exhibit;
    cin >> exhibit;
    
    int rotations = 0, curr, prev = 0;
    for (char c : exhibit)
    {
        curr = c - 'a';
        rotations += min(abs(curr - prev), 26 - abs(curr - prev));
        prev = curr;
    }
    
    cout << rotations << '\n';
    return 0;
}
