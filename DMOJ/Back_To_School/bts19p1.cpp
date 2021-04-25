#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, mini = -1; string sub[100], S;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> sub[i];
	cin >> S;

	for (int i = 0; i < N; i++) {
		if (sub[i].size() > S.size()) continue;
		if (mini == -1 || sub[i].size() > sub[mini].size()) mini = i;
	}
	cout << sub[mini] << '\n';
	return 0;
}
