#include <iostream>
#include <intrin.h>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;

	cout << __builtin_popcount(x) << '\n';
	return 0;
}
