#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, N; char ch; bool start = false;
    cin >> T >> N;

    for (int i = -N; i <= N; i++) {
        for (int j = -N; j <= N; j++) {
            cin >> ch;
            if (ch == 'B' && i == 0 && j == 0) start = true;
            if (ch == 'B' && abs(i) + abs(j) > T) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << (T == 0 && !start ? "NO" : "YES") << '\n';
    return 0;
}
