#include <stdio.h>
#include <string.h>

#define SS 1000000
#define TT 500000
char buf[SS + 1];

int main() {
	memset(buf, 'a', SS); buf[SS] = '\n';
	fwrite(buf, 1, SS + 1, stdout);
	buf[TT - 2] = 'b', buf[TT] = '\n';
	fwrite(buf, 1, TT + 1, stdout);
	return 0;
}