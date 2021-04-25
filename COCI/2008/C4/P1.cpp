#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a[5];
	for (int i = 0; i < 5; i++) cin >> a[i];

	while (true) {
		if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5) break;
		for (int i = 1; i < 5; i++) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				for (int i = 0; i < 5; i++) cout << a[i] << ' ';
				cout << '\n';
			}
		}
	}
	return 0;
}
