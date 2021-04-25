#include <bits/stdc++.h>
#define div(a, b) (a + b - 1) / b

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, R, W, B, Y, G;
	cin >> C >> R >> W >> B >> Y >> G;
	cout << max(0, C - (div(R, 4) + div(W, 5) + div(B, 4) + div(Y, 3) + div(G, 6))) << '\n';
	return 0;
}
