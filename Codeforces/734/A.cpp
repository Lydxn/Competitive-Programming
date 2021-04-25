#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int wins = 0;
	while (n--)
	{
		wins = s[n] == 'A' ? wins + 1 : wins - 1;
	}

	cout << (wins > 0 ? "Anton" : (wins < 0 ? "Danik" : "Friendship")) << '\n';
	return 0;
}
