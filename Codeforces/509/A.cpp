#include <iostream>

using namespace std;

const int seq[10] = { 1, 2, 6, 20, 70, 252, 924, 3432, 12870, 48620 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << seq[n - 1] << '\n';
	return 0;
}
