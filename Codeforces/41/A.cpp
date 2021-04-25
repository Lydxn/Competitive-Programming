#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	reverse(s.begin(), s.end());
	
	cout << (s == t ? "YES" : "NO") << '\n';
	return 0;
}
