#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int chair[1000001];
bool empty[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, x;
	cin >> N >> K;
	for (int i = 1; i <= K; i++) cin >> x, empty[x] = true;
	for (int i = 1; i <= K + 1; i++) {
		cin >> x;
		if (empty[x]) empty[x] = false;
		else chair[x] = i;
	}

	stack<int> st;
	do {
		for (int i = 1; i <= N; i++) {
			if (empty[i] && !st.empty()) st.pop(), empty[i] = false;
			else if (chair[i]) st.push(chair[i]), chair[i] = 0;
		}
	} while (st.size() != 1);
	cout << st.top() << '\n';
	return 0;
}
