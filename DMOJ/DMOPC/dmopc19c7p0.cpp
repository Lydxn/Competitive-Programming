#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	double A[4];
	cin >> A[0] >> A[1] >> A[2] >> A[3];

	cout << fixed << setprecision(10);
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			cout << (A[i] + A[j]) / 2 << '\n';
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 4; k++) {
				cout << (A[i] + A[j] + A[k]) / 3 << '\n';
			}
		}
	}
	cout << (A[0] + A[1] + A[2] + A[3]) / 4 << '\n';
	return 0;
}
