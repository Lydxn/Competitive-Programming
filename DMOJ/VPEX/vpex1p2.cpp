#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int x[10];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, sum = 0, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> x[i], sum += x[i];

    for (int i = 0; i < N; i++) {
        if (sum / N != x[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}
