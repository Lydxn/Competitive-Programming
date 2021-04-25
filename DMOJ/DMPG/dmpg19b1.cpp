#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C, sum = 0;
	cin >> N;
	while (N--) cin >> C, sum += C;

	if (sum > 200) cout << "Over maximum capacity!\n";
	else cout << 200 - sum << '\n';
	return 0;
}
