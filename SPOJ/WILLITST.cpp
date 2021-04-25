#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	cout << ((n & (n - 1)) == 0 ? "TAK" : "NIE") << '\n';
	return 0;
}
