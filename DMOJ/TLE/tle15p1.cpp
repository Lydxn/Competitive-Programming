#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pair<int, string> s[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, P, t;
	cin >> N >> P;
	for (int i = 0; i < N; i++) cin >> s[i].second;
	for (int i = 0; i < P; i++)
		for (int j = 0; j < N; j++) cin >> t, s[j].first += t;

	sort(s, s + N, greater<pair<int, string>>());
	for (int i = 0; i < N; i++) cout << 3 + i << ". " << s[i].second << '\n';
	return 0;
}
