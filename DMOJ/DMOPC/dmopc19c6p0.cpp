#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b > c && a + c > b && b + c > a ? "yes" : "no") << '\n';
    return 0;
}
