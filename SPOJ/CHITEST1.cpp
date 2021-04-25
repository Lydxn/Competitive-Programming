#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	float a, b;
	while (N--)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}
