#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    cin >> n;

    int sz = n.size(), i = 1;
    for (double res = 0; res < sz; i++) res += log10(i);

    if (n == "1" || n == "2") cout << n << '\n';
    else                  cout << i - 2 << '\n';
    return 0;
}
