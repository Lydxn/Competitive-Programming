#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a1 = 1, a2 = 1, a3 = 1;
	while (true)
	{
		cin >> a1 >> a2 >> a3;
		if (!a1 && !a2 && !a3) break;

		if (a2 - a1 == a3 - a2)
		{
			cout << "AP " << 2 * a3 - a2 << "\n";
		}
		else
		{
			cout << "GP " << a3 * a3 / a2 << "\n";
		}
	}
}
