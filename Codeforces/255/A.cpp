#include <bits/stdc++.h>

using namespace std;

int freq[3];
string exercise[] = {"chest", "biceps", "back"};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, max_val = 0, max_idx;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        freq[i % 3] += a;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (freq[i] > max_val)
        {
            max_val = freq[i];
            max_idx = i;
        }
    }
    
    cout << exercise[max_idx] << '\n';
    return 0;
}
