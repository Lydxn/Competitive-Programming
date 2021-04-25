#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, num, even_c = 0, even_i, odd_i;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		if (num % 2 == 0) even_i = i, even_c++;
		else			odd_i = i;
	}

	cout << (even_c == 1 ? even_i : odd_i) << '\n';
	return 0;
}
