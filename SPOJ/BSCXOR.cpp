#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	bool p, q;
	cin >> p >> q;

	cout << (p ^ q) << "\n";
	return 0;
}
