#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, c, k, w;
	cin >> t;

	while (t--)
	{
		cin >> c >> k >> w;
		cout << (c * w <= k ? "yes" : "no") << "\n";
	}
}
