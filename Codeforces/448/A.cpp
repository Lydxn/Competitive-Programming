#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a1, a2, a3, b1, b2, b3, n, sum_a, sum_b;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;

	sum_a = a1 + a2 + a3, sum_b = b1 + b2 + b3;
	while (n--)
	{
		if (sum_a > 0) sum_a -= 5;
		else if (sum_b > 0) sum_b -= 10;
		else break;
	}

	cout << (sum_a <= 0 && sum_b <= 0 ? "YES" : "NO") << '\n';
	return 0;
}
