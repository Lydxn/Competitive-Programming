#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	int count = 0, mod10;
	while (n)
	{
		mod10 = n % 10;
		if (mod10 == 4 || mod10 == 7) count++;
		n /= 10;
	}

	cout << (count == 4 || count == 7 ? "YES" : "NO");
}
