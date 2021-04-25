#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, ans = 0; bool flag = false;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    for (int i = 0; i < N; i++) {
        if (a[i] == b[i] && !flag) ++ans, flag = true;
        else if (a[i] != b[i]) flag = false;
    }

    cout << ans << '\n';
    return 0;
}
