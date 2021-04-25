#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, T, c, ans = INT_MAX;
    cin >> N >> T;
    
    vector<int> pos, neg;
    for (int i = 0; i < N; i++) {
        cin >> c;
        if (c < 0) neg.push_back(-c);
        else       pos.push_back(c);
    }
    sort(neg.begin(), neg.end()); sort(pos.begin(), pos.end());
    
    ans = pos.size() == T ? pos[T - 1] : INT_MAX;
    for (int i = 0; i < neg.size(); i++) {
        int j = T - i - 2;
        if (j < int(pos.size())) ans = min(ans, neg[i] + pos[j] + min(neg[i], pos[j]));
    }
    
    cout << ans << '\n';
    return 0;
}
