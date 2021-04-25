#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, grade, mod5;
	cin >> n;

	while (n--)
	{
		cin >> grade;
		
		mod5 = grade % 5;
		if (grade >= 38 && mod5 >= 3) grade += 5 - mod5;

		cout << grade << '\n';
	}
	return 0;
}
