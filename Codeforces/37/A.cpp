#include <bits/stdc++.h>

using namespace std;

int freq[1001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, l, height = 0, total = 0;
    cin >> N;
    
    while (N--)
    {
        cin >> l;
        ++freq[l];
    }
    
    for (int i : freq)
    {
        height = max(height, i);
        if (i) ++total;
    }
    
    cout << height << ' ' << total << '\n';
    return 0;
}
