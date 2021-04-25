#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int B[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> B[i], B[i] *= i;
	for (int i = 1; i <= N; i++) cout << B[i] - B[i - 1] << ' ';
	return 0;
}
