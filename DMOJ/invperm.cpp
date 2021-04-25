#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    if (K * 2 > N) {
        for (int i = N; i > K - N / 2 + 1; i--) cout << i << ' ';
        for (int i = K - N / 2; i > 0; i--) cout << i << ' ';
        cout << K - N / 2 + 1 << '\n';
    } else {
        for (int i = N; i > N - K; i--) cout << i << ' ';
        for (int i = K + 1; i <= N - K; i++) cout << i << ' ';
        for (int i = K; i > 0; i--) cout << i << ' ';
        cout << '\n';
    }
}
