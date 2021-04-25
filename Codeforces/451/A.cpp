#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	cout << (min(n, m) % 2 ? "Akshat" : "Malvika") << '\n';
	return 0;
}
