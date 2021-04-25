#include <bits/stdc++.h>

using namespace std;

bool hotel[10];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string events;
    cin >> n >> events;
    
    for (char e : events)
    {
        if (e == 'L')
        {
            int idx = 0;
            for (; idx < 10 && hotel[idx]; idx++);
            hotel[idx] = true;
        }
        else if (e == 'R')
        {
            int idx = 9;
            for (; idx >= 0 && hotel[idx]; idx--);
            hotel[idx] = true;
        }
        else hotel[e - '0'] = false;
    }
    
    for (bool b : hotel) cout << b;
    return 0;
}
