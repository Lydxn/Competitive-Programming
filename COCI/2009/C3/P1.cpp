#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string A, B;
	cin >> A >> B;

	reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
	cout << (stoi(A) > stoi(B) ? A : B) << '\n';
	return 0;
}
