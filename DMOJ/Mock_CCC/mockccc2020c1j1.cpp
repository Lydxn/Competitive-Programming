#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, minn = INT_MAX, maxx = 0;
    for (int i = 0; i < 4; i++) cin >> a, minn = min(minn, a), maxx = max(maxx, a);
    cout << minn << '\n' << maxx << '\n';
    return 0;
}
