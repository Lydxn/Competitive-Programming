#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, a;
	cin >> t;

	while (t--)
	{
		cin >> a;
		cout << (360 % (180 - a) == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
