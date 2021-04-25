#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Y;
	cin >> Y;

	vector<int> factors;
	for (int i = 2; i <= Y; i++) {
		while (Y % i == 0) Y /= i, factors.push_back(i);
	}

	for (int f : factors) cout << f << '\n';
	return 0;
}
