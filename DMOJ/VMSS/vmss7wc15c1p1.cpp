#include <bits/stdc++.h>
#define ID(i) (N[i] - '0')

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string N;
	cin >> N;
	cout << (ID(0) + ID(1) + ID(2) == ID(4) + ID(5) + ID(6) && ID(4) + ID(5) + ID(6) == ID(8) + ID(9) + ID(10) + ID(11) ? "Goony!" : "Pick up the phone!");
	return 0;
}
