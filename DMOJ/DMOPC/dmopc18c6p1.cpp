#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; char ch; bool T = false, U = false;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch;
		T |= ch == 'T', U |= ch == 'U';
		if (ch != 'A' && ch != 'C' && ch != 'G' && ch != 'T' && ch != 'U') {
			cout << "neither\n";
			return 0;
		}
	}

	cout << (T != U ? T ? "DNA" : "RNA" : T && U ? "neither" : "both") << '\n';
	return 0;
}
