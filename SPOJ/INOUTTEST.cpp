#include <iostream>
#pragma GCC optimize "O3"
#define gc() (*_pbuf ? *_pbuf++ : (in_buf[fread_unlocked(_pbuf = in_buf, 1, 65536, stdin)] = 0, *_pbuf++))

char in_buf[65536], out_buf[65536], *_pbuf = in_buf;

inline int scan() 
{
	int n = 0, c, o = 0;
	while ((c = gc()) < 48) n |= c == 45;
	do o = o * 10 + c - 48;
	while ((c = gc()) >= 48);
	return n ? -o : o;
}

inline void print(int n) 
{
	if (n < 0) 
	{
		n = -n;
		putchar_unlocked('-');
	}
	int i = 10;
	do 
	{
		out_buf[--i] = n % 10 + '0';
		n /= 10;
	} while (n);
	do putchar_unlocked(out_buf[i]);
	while (++i < 10);
	putchar_unlocked('\n');
}

int main()
{
	int N = scan();
	while (N--)
	{
		print(scan() * scan());
	}
	return 0;
}
