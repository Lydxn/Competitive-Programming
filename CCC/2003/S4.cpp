/*
Fast O(|S|^2) method using a fast hashing method. *CHEESE*
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 5001;
int pre[MAXN], hsh[MAXN], HASH = 131, MOD = (1 << 29) - 1;
gp_hash_table<int, null_type> uset;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    pre[0] = 1;
    for (int i = 1; i < MAXN; i++) pre[i] = (pre[i - 1] * HASH) & MOD;
    
    int N, cnt, len;
    string S;
    cin >> N;
    
    while (N--)
    {
        cin >> S;
        
        cnt = 1, len = S.size();
        for (int i = 1; i <= len; i++) hsh[i] = (hsh[i - 1] * HASH + S[i - 1]) & MOD;
        
        for (int i = 1; i <= len; i++)
        {
            uset.clear();
            for (int j = i; j <= len; j++) uset.insert((hsh[j] - hsh[j - i] * pre[i]) & MOD);
            cnt += uset.size();
        }
        cout << cnt << '\n';
    }
    return 0;
}
