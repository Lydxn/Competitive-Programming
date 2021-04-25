#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, ones = 0, zeros = 0;
	string bstr;
	cin >> n >> bstr;

	for (char c : bstr)
	{
		if (c == '1') ++ones;
		else		  ++zeros;
	}

	cout << n - 2 * min(ones, zeros);
	return 0;
}
