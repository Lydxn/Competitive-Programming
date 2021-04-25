#include <bits/stdc++.h>

using namespace std;

int perm[50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, L, S;
	cin >> N;

	while (N--) {
		cin >> L;
		for (int i = 0; i < L; i++) cin >> perm[i];

		S = 0;
		for (int i = 0; i < L - 1; i++) {
			for (int j = i + 1; j < L; j++) {
				if (perm[i] > perm[j]) ++S;
			}
		}
		cout << "Optimal train swapping takes " << S << " swaps.\n";
	}
	return 0;
}
