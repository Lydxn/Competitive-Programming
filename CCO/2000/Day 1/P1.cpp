#include <bits/stdc++.h>

using namespace std;

vector<int> adj[26];
bool visited[26], has[26], ans[26][26];

void dfs(int curr, int prev)
{
    if (prev != -1) for (int i = 0; i < 26; i++) ans[curr][i] |= ans[prev][i];
    
    if (!visited[curr])
    {
        visited[curr] = true;
        for (int i : adj[curr]) dfs(i, curr);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    char X, S; string _;
    while (N--)
    {
        cin >> X >> _ >> S;
        memset(visited, false, sizeof(visited));
        
        has[X - 'A'] = true;
        if ('a' <= S && S <= 'z')
        {
            ans[X - 'A'][S - 'a'] = true;
            dfs(X - 'A', -1);
        }
        else
        {
            has[S - 'A'] = true;
            adj[S - 'A'].push_back(X - 'A');
            dfs(S - 'A', -1);
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (has[i])
        {
            cout << char(i + 'A') << " = {";
            for (int j = 0, flag = 0; j < 26; j++)
            {
                if (ans[i][j])
                {
                    if (flag) cout << ',';
                    cout << char(j + 'a');
                    flag = 1;
                }
            }
            cout << "}\n";
        }
    }
    return 0;
}
