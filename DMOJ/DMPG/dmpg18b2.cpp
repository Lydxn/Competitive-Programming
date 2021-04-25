#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	cout << min(N, M - 1) << '\n';
	return 0;
}
