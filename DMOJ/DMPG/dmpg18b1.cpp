#include <bits/stdc++.h>
#define div3(x) (x + 2) / 3

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int P, C, V;
	cin >> P >> C >> V;
	cout << div3(P) + div3(C) + div3(V) << '\n';
	return 0;
}
