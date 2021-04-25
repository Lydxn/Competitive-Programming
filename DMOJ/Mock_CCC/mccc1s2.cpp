#include <bits/stdc++.h>

using namespace std;

bool a[2000][2000], cpy[2000][2000];
vector<string> sol;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; char ch;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ch;
            a[i][j] = ch == '1';
            cpy[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (!a[i][0]) {
            sol.push_back("R " + to_string(i + 1));
            for (int j = 0; j < N; j++) cpy[i][j] ^= 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (a[0][i] == a[0][0]) {
            sol.push_back("C " + to_string(i + 1));
            for (int j = 0; j < N; j++) cpy[j][i] ^= 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cpy[i][j]) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << sol.size() << '\n';
    for (auto s : sol) cout << s << '\n';
    return 0;
}
