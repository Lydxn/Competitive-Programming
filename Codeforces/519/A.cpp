#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> weight = {{'.', 0}, {'Q', 9}, {'R', 5}, {'B', 3}, {'N', 3}, {'P', 1}, {'K', 0}, {'q', -9}, {'r', -5}, {'b', -3}, {'n', -3}, {'p', -1}, {'k', 0}};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int eval = 0;
    string rank;
    
    for (int i = 0; i < 8; i++)
    {
        cin >> rank;
        for (int j = 0; j < 8; j++)
        {
            eval += weight[rank[j]]; 
        }
    }
    
    cout << (eval > 0 ? "White" : eval < 0 ? "Black" : "Draw") << '\n';
    return 0;
}
