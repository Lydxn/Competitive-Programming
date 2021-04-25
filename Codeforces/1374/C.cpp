#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n; string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		stack<char> st; int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') st.push(s[i]);
			else {
				if (!st.empty() && st.top() == '(') st.pop();
				else ++cnt;
			}
		}
		cout << (cnt + int(st.size()) + 1) / 2 << '\n';
	}
	return 0;
}
