#include <cmath>
#include <iostream>

using namespace std;

void rotate_3d(double& x, double& y, double& z, double& rx, double& ry, double& rz, double& theta)
{
	double c = cos(theta);
	double s = sin(theta);
	double sq = sqrt(rx * rx + ry * ry + rz * rz);

	rx /= sq, ry /= sq, rz /= sq;
	double cm1 = 1 - c;
	double xyc = rx * ry * cm1;
	double xzc = rx * rz * cm1;
	double yzc = ry * rz * cm1;
	double rxs = rx * s;
	double rys = ry * s;
	double rzs = rz * s;

	double xp = (c + rx * rx * cm1) * x +
		(xyc - rzs) * y +
		(xzc + rys) * z;
	double yp = (c + ry * ry * cm1) * y +
		(yzc - rxs) * z +
		(xyc + rzs) * x;
	double zp = (c + rz * rz * cm1) * z +
		(xzc - rys) * x +
		(yzc + rxs) * y;

	printf("%.6f %.6f %.6f\n", xp, yp, zp);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	double x, y, z, rx, ry, rz, theta;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y >> z >> rx >> ry >> rz >> theta;
		rotate_3d(x, y, z, rx, ry, rz, theta);
	}
}
