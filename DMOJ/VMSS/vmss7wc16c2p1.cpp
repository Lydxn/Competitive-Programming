#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string G = "GGGGGG....G..GGG...GGGGGG";

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 5; k++) cout << string(N, G[i * 5 + k]);
			cout << '\n';
		}
	}
	return 0;
}
