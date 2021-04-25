#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int T, M;
    string X, C;
    deque<string> dq;
    cin >> T >> M;
    
    while (T--) {
        cin >> X >> C;
        if (C[0] == 'i') dq.push_back(X);
        else {
            if (dq.back() == X) dq.pop_back();
            else if (dq.front() == X && M--) dq.pop_front();
        }
    }
    
    for (string s : dq) cout << s << '\n';
    return 0;
}
