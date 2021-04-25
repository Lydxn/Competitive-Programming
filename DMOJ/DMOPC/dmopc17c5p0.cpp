#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int B, P; char V;
	cin >> B >> P >> V;

	if (P * 5 <= B) cout << (V == 'Y' ? 'B' : 'A') << '\n';
	else if (P * 2 <= B) cout << (V == 'Y' ? 'D' : 'C') << '\n';
	else cout << "NO PIZZA\n";
	return 0;
}
