#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int a, b, mid;
	cin >> a >> b;

	char ans[5];
	while (true)
	{
		mid = (a + b) >> 1;
		cout << mid << "\n";
		fflush(stdout);

		scanf("%s", ans);
		if (strcmp(ans, "LOW") == 0) a = mid + 1;
		else if (strcmp(ans, "HIGH") == 0) b = mid - 1;
		else if (strcmp(ans, "WIN") == 0) return 0;
	}
}
