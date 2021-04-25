#include <bits/stdc++.h>

using namespace std;

double ncr(int n, int r)
{
    r = min(r, n - r);
    
    int res = 1;
    for (int i = 1; i <= r; i++) res = res * (n - r + i) / i;
    return res;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    int num_p = 0, num_q = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '+') ++num_p;
        if (s2[i] == '+') --num_p;
        if (s2[i] == '?') ++num_q;
    }

    cout << fixed << setprecision(12);
    cout << (num_p >= 0 && num_p <= num_q ? ncr(num_q, num_p) / (1 << num_q) : 0) << '\n';
    return 0;
}
