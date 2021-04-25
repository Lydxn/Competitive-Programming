#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string A, B; char op;
	cin >> A >> op >> B;

	int alen = A.size(), blen = B.size();
	if (op == '+') cout << (alen == blen ? "2" + string(alen - 1, '0') : "1" + string(abs(alen - blen) - 1, '0') + "1" + string(min(alen, blen) - 1, '0')) << '\n';
	else cout << "1" + string(alen + blen - 2, '0');
	return 0;
}
