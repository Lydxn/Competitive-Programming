#include <bits/stdc++.h>

using namespace std;

string f[201];

string add(string a, string b)
{
    string res = "";
    int carry = 0, sum, alen = a.size(), blen = b.size();
    
    for (int i = alen - 1; i >= 0; i--)
    {
        sum = (a[i] - '0') + (b[i + blen - alen] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    
    for (int i = blen - alen - 1; i >= 0; i--)
    {
        sum = (b[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    
    if (carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    f[0] = "0", f[1] = "1";
    for (int i = 2; i <= 200; i++) f[i] = add(f[i - 2], f[i - 1]);
    
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        cout << f[n] << '\n';
    }
    return 0;
}
