#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi find_divisors(int n)
{
	vi res;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			res.push_back(i);
			if (n / i != i) res.push_back(n / i);
		}
	}
	return res;
}

bool is_lucky(int a)
{
	while (a)
	{
		if (a % 10 != 4 && a % 10 != 7) return false;
		a /= 10;
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vi divisors = find_divisors(n);

	bool almost_lucky = false;
	for (auto& a : divisors)
	{
		if (is_lucky(a)) almost_lucky = true;
	}

	cout << (almost_lucky ? "YES" : "NO") << '\n';
	return 0;
}
