#include <bits/stdc++.h>

using namespace std;

int cards[1000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cards[i];
    
    int s_sum = 0, s_ptr = 0, d_sum = 0, d_ptr = n - 1;
    for (int i = 0; s_ptr <= d_ptr; i++)
    {
        if (i % 2) d_sum += cards[cards[s_ptr] > cards[d_ptr] ? s_ptr++ : d_ptr--];
        else       s_sum += cards[cards[s_ptr] > cards[d_ptr] ? s_ptr++ : d_ptr--];
    }
    
    cout << s_sum << ' ' << d_sum << '\n';
    return 0;
}
