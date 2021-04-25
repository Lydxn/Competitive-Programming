#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pair<char, int> att[2000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H, h1, h2;
	cin >> N >> H; h1 = h2 = H;

	for (int i = 0; i < N; i++) cin >> att[i << 1].first >> att[i << 1].second;
	for (int i = 0; i < N; i++) cin >> att[i << 1 | 1].first >> att[i << 1 | 1].second;

	for (int i = 0; i < N << 1; i++) {
		if (att[i].first == 'A') {
			if (i % 2) h1 -= att[i].second;
			else h2 -= att[i].second;
		} else {
			if (att[i + 1].first == 'A') {
				i++;
				continue;
			} else {
				if (i % 2) h2 -= att[i].second;
				else h1 -= att[i].second;
			}
		}
		if (h1 <= 0) {
			cout << "DEFEAT\n";
			return 0;
		}
		if (h2 <= 0) {
			cout << "VICTORY\n";
			return 0;
		}
	}

	cout << "TIE\n";
	return 0;
}
