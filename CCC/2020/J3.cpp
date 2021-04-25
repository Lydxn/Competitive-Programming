#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, X, Y, minx = INT_MAX, miny = INT_MAX, maxx = 0, maxy = 0; string S;
	cin >> N;
	while (N--) {
		cin >> S;
		X = stoi(S.substr(0, S.find_first_of(','))), Y = stoi(S.substr(S.find_first_of(',') + 1));
		minx = min(minx, X), miny = min(miny, Y), maxx = max(maxx, X), maxy = max(maxy, Y);
	}

	cout << minx - 1 << ',' << miny - 1 << '\n' << maxx + 1 << ',' << maxy + 1 << '\n';
	return 0;
}
