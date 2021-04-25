#include <iostream>
#pragma GCC optimize "Ofast"

using namespace std;

char buf[65536];

int main()
{
	int c, n, k, i, t = 0, cnt = 0;
	scanf("%d %d\n", &n, &k);

	while (c = fread(buf, 1, 65536, stdin))
	{
		for (i = 0; i < c; ++i)
		{
			if (buf[i] == '\n')
			{
				if (t % k == 0) ++cnt;
				t = 0;
			}
			else
			{
				t = t * 10 + buf[i] - '0';
			}
		}
	}

	printf("%d", cnt);
	return 0;
}
