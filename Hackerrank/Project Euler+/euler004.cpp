#include <iostream>
#include <set>

using namespace std;

set<int> palindromes;

bool is_palindrome(int n)
{
	int temp = n, rev = 0;
	while (n)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return temp == rev;
}

void init_palindromes()
{
	int prod;
	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100000 / i + 1; j < 1000; j++)
		{
			prod = i * j;
			if (is_palindrome(prod)) palindromes.insert(prod);
		}
	}
}

int main()
{
	init_palindromes();
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << *--palindromes.lower_bound(N) << '\n';
	}
	return 0;
}
