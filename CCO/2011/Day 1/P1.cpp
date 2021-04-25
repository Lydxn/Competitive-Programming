#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll, double> scores[100000];
double range[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, idx = 0; ll myscore;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> scores[i].first >> scores[i].second;

	sort(scores, scores + N, greater<pair<ll, double>>());
	range[0] = scores[0].second - 1;
	for (int i = 1; i < N; i++) range[i] = scores[i].second - (scores[i - 1].second + range[i - 1]) - 1;

	cin >> myscore;
	for (int i = 0; i < N; i++) {
		if (scores[i].first == myscore) {
			idx = i;
			break;
		}
	}

	cout << ll(scores[idx].second - range[idx]) << '\n' << ll(scores[idx].second + range[idx]) << '\n';
	return 0;
}
