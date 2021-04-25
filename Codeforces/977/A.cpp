#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	while (k--) n = n % 10 ? n - 1 : n / 10;
	
	cout << n << '\n';
	return 0;
}
