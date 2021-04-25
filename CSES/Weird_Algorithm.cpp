#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

    ll n;
    cin >> n;

    while (n != 1) {
        cout << n << ' ';
        n = n % 2 ? 3 * n + 1 : n / 2;
    }
    cout << "1\n";
	return 0;
}
