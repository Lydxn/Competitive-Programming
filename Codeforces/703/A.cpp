#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, c, wins = 0;
	cin >> n;

	while (n--)
	{
		cin >> m >> c;
		if (m > c)		wins++;
		else if (m < c) wins--;
	}

	cout << (wins > 0 ? "Mishka" : wins < 0 ? "Chris" : "Friendship is magic!^^") << '\n';
	return 0;
}
