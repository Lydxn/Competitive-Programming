#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int S, M, L;
	cin >> S >> M >> L;

	cout << (S + 2 * M + 3 * L >= 10 ? "happy" : "sad") << '\n';
	return 0;
}
