#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int vil[100];
vector<int> songs[101];
unordered_set<int> knows;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, E, K, s = 0;
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		cin >> K; bool one = false;
		for (int j = 0; j < K; j++) cin >> vil[j], one |= vil[j] == 1;
		if (one) {
			++s;
			for (int j = 0; j < K; j++) songs[vil[j]].push_back(s);
		} else {
			for (int j = 0; j < K; j++) for (int k : songs[vil[j]]) knows.insert(k);
			for (int j = 0; j < K; j++) songs[vil[j]].assign(knows.begin(), knows.end());
		}
	}

	for (int i = 1; i <= N; i++) if (int(songs[i].size()) == s) cout << i << '\n';
	return 0;
}
