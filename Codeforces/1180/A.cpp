#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << 2 * n * (n - 1) + 1;
	return 0;
}
