#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string players;
	cin >> players;

	bool dangerous = players.find(string(7, '1')) != string::npos ||
					 players.find(string(7, '0')) != string::npos;
	cout << (dangerous ? "YES" : "NO") << '\n';
	return 0;
}
