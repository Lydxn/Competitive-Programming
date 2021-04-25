#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a[5];
	for (int i = 0; i < 5; i++) cin >> a[i];
	a[2] /= 2, a[3] /= 7, a[4] /= 4;

	cout << *min_element(a, a + 5) << '\n';
	return 0;
}
