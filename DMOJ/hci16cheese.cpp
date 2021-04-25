#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		cout << (M < 3 ? "-1" : "(2,3)") << "\n";
	}
	return 0;
}
