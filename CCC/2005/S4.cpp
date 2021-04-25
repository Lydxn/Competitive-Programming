#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> names;
vector<int> adj[1001];

int dfs(int curr, int prev) {
    int res = 1;
    for (int i : adj[curr]) {
        if (i != prev) res = max(res, dfs(i, curr) + 1);
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int L, n, root;
    string p1, p2;
    cin >> L;
    
    while (L--) {
        cin >> n;
        names.clear();
        for (int i = 0; i < n; i++) adj[i].clear();
        
        for (int i = 0, idx = 0; i < n / 2; i++) {
            cin >> p1 >> p2;
            if (names.find(p1) == names.end()) names[p1] = idx++;
            if (names.find(p2) == names.end()) names[p2] = idx++;
            
            adj[names[p1]].push_back(names[p2]); adj[names[p2]].push_back(names[p1]);
            root = names[p2];
        }
        cout << (n - dfs(root, -1) * 2 + 2) * 10 << '\n';
    }
    return 0;
}
