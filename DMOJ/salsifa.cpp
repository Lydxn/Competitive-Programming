#include <bits/stdc++.h>

using namespace std;

bool grid[75][75];
int N;

void copy_mirror(int sr, int sc, int dr, int dc, bool horiz) {
    for (int i = 0; i < N; i++) memcpy(*(grid + i + dr) + dc, *(grid + i + sr) + sc, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N >> 1; j++) {
            if (horiz) swap(grid[i + dr][j + dc], grid[i + dr][dc + N - j - 1]);
            else       swap(grid[j + dr][i + dc], grid[dr + N - j - 1][i + dc]);
        }
    }
}

void print() {
    for (int i = 30 - N; i < 30 + N + N; i++) {
        for (int j = 30 - N; j < 30 + N + N; j++) {
            if (j != 30 - N) cout << ' ';
            cout << (grid[i][j] ? 'X' : ' ');
        }
        cout << '\n';
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N; cin.ignore(); string s;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        for (int j = 0; j < N; j++) {
            grid[i + 30][j + 30] = s[j] == 'X';
        }
    }

    copy_mirror(30, 30, 30, 30 - N, 1); copy_mirror(30, 30, 30 - N, 30, 0);
    copy_mirror(30, 30, 30, 30 + N, 1); copy_mirror(30, 30, 30 + N, 30, 0);
    copy_mirror(30 - N, 30, 30 - N, 30 - N, 1); copy_mirror(30 - N, 30, 30 - N, 30 + N, 1);
    copy_mirror(30, 30 - N, 30 - N, 30 - N, 0); copy_mirror(30, 30 - N, 30 - N, 30 - N, 0);
    copy_mirror(30, 30 + N, 30 - N, 30 + N, 0); copy_mirror(30, 30 + N, 30 + N, 30 + N, 0);
    copy_mirror(30 + N, 30, 30 + N, 30 - N, 1); copy_mirror(30 + N, 30, 30 + N, 30 + N, 1);

    for (int i = 0, N3 = N + N + N, OFF = 30 - N; i < N3; i++) {
        for (int j = 0; j < N3 - i - 1; j++) {
            if (grid[i + OFF][j + OFF] != grid[N3 - j - 1 + OFF][N3 - i - 1 + OFF]) {
                goto nxt1;
            }
        }
    }
    print(); return 0; nxt1:;

    for (int i = 0, N3 = N + N + N, OFF = 30 - N; i < N3; i++) {
        for (int j = 0; j < N3 - i - 1; j++) {
            if (grid[i + OFF][N3 - j - 1 + OFF] != grid[N3 - j - 1 + OFF][i + OFF]) {
                goto nxt2;
            }
        }
    }
    print(); return 0; nxt2:;

    for (int i = 0, N3 = N + N + N, OFF = 30 - N; i < N3; i++) {
        for (int j = 0; j < N3 >> 1; j++) {
            if (grid[i + OFF][j + OFF] != grid[i + OFF][N3 - j - 1 + OFF]) {
                goto nxt3;
            }
        }
    }
    print(); return 0; nxt3:;

    for (int i = 0, N3 = N + N + N, OFF = 30 - N; i < N3; i++) {
        for (int j = 0; j < N3 >> 1; j++) {
            if (grid[j + OFF][i + OFF] != grid[N3 - j - 1 + OFF][i + OFF]) {
                cout << "Offer Denied\n";
                return 0;
            }
        }
    }
    print(); return 0;
}
