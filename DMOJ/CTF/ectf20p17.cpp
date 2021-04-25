#include <bits/stdc++.h>

using namespace std;

string s;
int a, b, c;

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main() {
	cout << 1 << endl << 7 << endl;
	while (true) {
		getline(cin, s);
		if (is_number(s)) {
			a = stoi(s);
			cin >> s;
			b = stoi(s);
			cin >> s;
			c = stoi(s);
			break;
		}
	}

	for (long long i = 1595473283; ; i++) {
		srand(i);
		if (rand() == a && rand() == b && rand() == c) {
			int dummy = rand() + rand() + rand() + rand();
			if (dummy != -1)
				cout << 2 << endl << rand() << endl;
			break;
		}
	}
	return 0;
}
