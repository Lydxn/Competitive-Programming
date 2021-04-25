#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int hh, mm, ss;
	char meridem[2];
	scanf("%d:%d:%d%s", &hh, &mm, &ss, &meridem);

	if (strcmp(meridem, "PM") == 0 && hh != 12) hh += 12;
	if (strcmp(meridem, "AM") == 0 && hh == 12) hh = 0;

	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}
