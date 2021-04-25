#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int M[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> M[i];

	sort(M, M + N, [&] (int& a, int& b) { return a % K == b % K ? a < b : a % K < b % K; });
	for (int i = 0; i < N; i++) cout << M[i] << ' ';
	cout << '\n';
	return 0;
}
