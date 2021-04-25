#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long double a, b, c, s, r, ga, gb, gc, area, dist;
	cout << fixed;

	while (n--)
	{
		cin >> a >> ga >> gb >> gc;
		b = a * ga / gb;
		c = a * ga / gc;

		s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));

		r = a * b * c / (4 * area);
		dist = 2 * sqrt(9 * r * r - a * a - b * b - c * c) / 3;

		cout << setprecision(3) << area << ' ' << dist << '\n';
	}
	return 0;
}
