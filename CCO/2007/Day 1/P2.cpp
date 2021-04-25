#include <bits/stdc++.h>

using namespace std;

unordered_set<string> h;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while (n--) {
        deque<int> flake(6), mini;
        for (int i = 0; i < 6; i++) cin >> flake[i];
        mini = flake;
        
        for (int i = 0; i < 6; i++) {
            flake.push_back(flake.front()); flake.pop_front();
            mini = min(mini, flake);
        }
        reverse(flake.begin(), flake.end());
        for (int i = 0; i < 6; i++) {
            flake.push_back(flake.front()); flake.pop_front();
            mini = min(mini, flake);
        }
        
        string s = "";
        for (int i = 0; i < 6; i++) s += to_string(mini[i]);
        if (h.count(s)) {
            cout << "Twin snowflakes found.\n";
            return 0;
        }
        h.insert(s);
    }
    
    cout << "No two snowflakes are alike.\n";
}
