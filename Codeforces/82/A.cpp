#include <iostream>

using namespace std;

const string people[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	n--;
	while (n >= 5) n = (n - 5) / 2;

	cout << people[n] << '\n';
	return 0;
}
