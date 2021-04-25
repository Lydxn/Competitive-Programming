#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

template <typename Container>
void split(const string& str, Container& cont, char delim = ' ') {
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) cont.push_back(token);
}

vector<string> words;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string s;
	cin >> N; cin.ignore();
	while (N--) {
		getline(cin, s);
		for (char &c : s) c = tolower(c);
		words.clear(); split(s, words);
		int sz = words.size();

		if (words[0].size() > 1 && words[0].substr(words[0].size() - 2) == "'s") {
			cout << "Set\n";
			continue;
		}

		if (words[0] == "damaged") {
			cout << "Normal\n";
			continue;
		}

		if (sz == 2) {
			if (words[0] == "of")
				cout << "Rare\n";
			else
				cout << "Not sure, take anyways\n";
			continue;
		}

		if (sz > 2 && sz <= 4 && words[sz - 2] == "of")
			cout << "Magic\n";
		else
			cout << "Normal\n";
	}
	return 0;
}
