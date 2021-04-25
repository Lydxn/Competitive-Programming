#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;

	// weird mathy answer?
	cout << (1LL << (N >> 1LL)) << '\n';
	return 0;
}
