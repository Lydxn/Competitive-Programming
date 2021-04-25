#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x, N;
    cin >> x >> N;

    cout << x / N << ' ' << x % N << '\n';
    return 0;
}
