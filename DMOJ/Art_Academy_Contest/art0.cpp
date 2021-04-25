#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string S;
	cin >> N;

	while (N--) {
		cin >> S;
		for (char i : S) {
			char c = toupper(i);
			if (c == 'A') cout << "Hi! ";
			else if (c == 'E') cout << "Bye! ";
			else if (c == 'I') cout << "How are you? ";
			else if (c == 'O') cout << "Follow me! ";
			else if (c == 'U') cout << "Help! ";
			else if (c >= '0' && c <= '9') cout << "Yes! ";
		}
		cout << '\n';
	}
	return 0;
}
