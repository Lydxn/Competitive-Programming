#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string guest, host, pile;
	cin >> guest >> host >> pile;

	guest.append(host);
	sort(guest.begin(), guest.end());
	sort(pile.begin(), pile.end());

	cout << (guest == pile ? "YES" : "NO") << '\n';
	return 0;
}
