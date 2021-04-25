#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> two_gram;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, max_freq = 0;
    string s, max_gram;
    cin >> n >> s;
    
    for (int i = 0; i < n - 1; i++) ++two_gram[s.substr(i, 2)];
    
    for (auto const& g : two_gram)
    {
        if (g.second > max_freq)
        {
            max_freq = g.second;
            max_gram = g.first; 
        }
    }
    
    cout << max_gram << '\n';
    return 0;
}
