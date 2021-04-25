#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;

	string str;
	for (int i = 1; i <= N; i++)
	{
		cin >> M >> str;
		cout << i << " " << str.erase(M - 1, 1) << "\n";
	}
	return 0;
}
