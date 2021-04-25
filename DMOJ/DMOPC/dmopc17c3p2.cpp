#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool towers[100001], temp[100001];
vector<int> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; char ch;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> ch, towers[i] = ch == '1';

	memcpy(temp, towers, N);
	for (int i = 0; i < N - 1; i++) if (temp[i]) temp[i] ^= 1, temp[i + 1] ^= 1, temp[i + 2] ^= 1, ans.push_back(i + 1);

	if (temp[N - 1]) {
		memcpy(temp, towers, N); temp[0] ^= 1, temp[1] ^= 1; ans = {0};
		for (int i = 0; i < N - 1; i++) if (temp[i]) temp[i] ^= 1, temp[i + 1] ^= 1, temp[i + 2] ^= 1, ans.push_back(i + 1);
	}

	cout << ans.size() << '\n';
	for (int a : ans) cout << a + 1 << '\n';
	return 0;
}
