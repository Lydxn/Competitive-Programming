#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> factors = {{'0', ""}, {'1', ""}, {'2', "2"}, {'3', "3"}, {'4', "223"}, {'5', "5"}, {'6', "35"}, {'7', "7"}, {'8', "2227"}, {'9', "2337"}};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    string a, res = "";
    cin >> n >> a;
    
    for (int i = 0; i < n; i++) res += factors[a[i]];
    sort(res.begin(), res.end(), greater<int>());
    
    cout << res << '\n';
    return 0;
}
