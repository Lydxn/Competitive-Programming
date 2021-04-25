#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	cin >> n >> num;
	n--;

	int count = 0, min = num, max = num;
	while (n--)
	{
		cin >> num;
		if (num < min)
		{
			min = num;
			count++;
		} 
		
		if (num > max)
		{
			max = num;
			count++;
		}
	}

	cout << count << '\n';
	return 0;
}
