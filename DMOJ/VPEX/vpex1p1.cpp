#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a[5], b[5];
    for (int i = 0; i < 5; i++) cin >> a[i];
    for (int i = 0; i < 5; i++) cin >> b[i];
    sort(a, a + 5); sort(b, b + 5);

    cout << max(a[1] + a[2] + a[3] + a[4], b[1] + b[2] + b[3] + b[4]) << '\n';
    return 0;
}
