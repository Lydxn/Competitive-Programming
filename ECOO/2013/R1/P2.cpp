#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) {
		string res = "", num;
		for (int i = 0; i < 5; i++) {
			cin >> num;
			int sum = 0;
			for (int j = num.size() - 1; j >= 0; j -= 2) {
				int cur = 2 * (num[j] - '0');
				while (cur) sum += cur % 10, cur /= 10;
			}
			for (int j = num.size() - 2; j >= 0; j -= 2) sum += num[j] - '0';
			res += to_string((10 - sum % 10) % 10);
		}
		cout << res << '\n';
	}
	return 0;
}
