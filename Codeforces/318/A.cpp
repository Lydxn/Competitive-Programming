#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;

	long long half = (n + 1) / 2;
	cout << (k <= half ? k * 2 - 1 : (k - half) * 2) << '\n';
	return 0;
}
