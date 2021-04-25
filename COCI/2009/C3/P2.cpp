#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, K;
	cin >> C >> K;

	int p10 = pow(10, K);
	cout << (C % p10 >= p10 / 2 ? C - C % p10 + p10 : C - C % p10) << '\n';
	return 0;
}
