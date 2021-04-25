#include <bits/stdc++.h>
#define f(x) int(sqrt(x))

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R1, G1, B1, R2, G2, B2;
	cin >> R1 >> G1 >> B1 >> R2 >> G2 >> B2;

	cout << (f(R1) == f(R2) && f(G1) == f(G2) && f(B1) == f(B2) ? "Dull" : "Colourful") << '\n';
	return 0;
}
