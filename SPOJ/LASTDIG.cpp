#include <cmath>
#include <iostream>

using namespace std;

int last_dig(int a, int b)
{
	if (a && !b) return 1;
	int exp = b & 3;
	return (int) pow(a % 10, !exp ? 4 : exp) % 10;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, a, b;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << last_dig(a, b) << "\n";
	}
	return 0;
}
