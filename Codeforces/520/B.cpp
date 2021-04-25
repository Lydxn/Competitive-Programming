#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, presses = 0;
	cin >> n >> m;

	while (n < m)
	{
		if (m & 1) ++m;
		else	   m >>= 1;
		++presses;
	}
	
	cout << presses + n - m << '\n';
	return 0;
}
