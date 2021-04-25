#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a[3], b[3], alice = 0, bob = 0;

	for (int i = 0; i < 3; i++) cin >> a[i];
	for (int i = 0; i < 3; i++) cin >> b[i];

	for (int i = 0; i < 3; i++)
	{
		if (a[i] > b[i]) alice++;
		else if (a[i] < b[i]) bob++;
	}

	cout << alice << ' ' << bob << '\n';
	return 0;
}
