#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, int> mp;
string name[20];
deque<int> votes[10000];
int cnt[20], elim[20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, X; string c;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> name[i], mp[name[i]] = i;
	for (int i = 0; i < M; i++) {
		cin >> X;
		for (int j = 0; j < X; j++) cin >> c, votes[i].push_back(mp[c]);
	}

	for (int i = 0; i < N - 1; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < M; j++) {
			while (!votes[j].empty() && elim[votes[j].front()]) votes[j].pop_front();
			if (!votes[j].empty()) ++cnt[votes[j].front()];
		}

		int mn = INT_MAX, mi = -1;
		for (int j = 0; j < N; j++)
			if (!elim[j] && cnt[j] < mn)
				mn = cnt[j], mi = j;
		elim[mi] = true;
	}

	for (int i = 0; i < N; i++) {
		if (!elim[i]) {
			cout << name[i] << '\n';
			break;
		}
	}
	return 0;
}
