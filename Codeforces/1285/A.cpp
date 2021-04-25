#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, cntl = 0, cntr = 0; string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cntl += s[i] == 'L', cntr += s[i] == 'R';
	cout << cntl + cntr + 1 << '\n';
	return 0;
}
