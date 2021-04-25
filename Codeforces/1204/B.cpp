#include <bits/stdc++.h>

using namespace std;

int pow2[21];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    pow2[0] = 1;
    for (int i = 1; i < 21; i++) pow2[i] = pow2[i - 1] << 1;
    
    int n, l, r, mini = 0, maxi = 0;
    cin >> n >> l >> r;
    
    for (int i = 0; i < l; i++) mini += pow2[i];
    mini += n - l;
    
    for (int i = 0; i < r; i++) maxi += pow2[i];
    maxi += (n - r) * pow2[r - 1];
    
    cout << mini << ' ' << maxi << '\n';
    return 0;
}
