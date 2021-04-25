#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int w;
	cin >> w;

	cout << (w % 2 == 0 && w != 2 ? "YES" : "NO") << '\n';
	return 0;
}
