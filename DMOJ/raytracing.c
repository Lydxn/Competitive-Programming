// stupidly fast brute-force solution

#include <stdio.h>
#pragma GCC optimize "Ofast,unroll-loops"

char _i[41 << 20], _o[11 << 20];
#define scanu(x) { for (x=_i[_i0++]-48; 47<(_=_i[_i0++]); x=x*10+_-48); }

int main() {
	fread(_i, 1, 41 << 20, stdin);
	char _; int h[1 << 13], N, Q, l, r, a, b, t, cnt, _i0 = 0, _o0 = 0;
	scanu(N);
	for (int i = 0; i < N; i++) { scanu(a); h[i] = a; }
	scanu(Q);

	while (Q--) {
		if (_i[_i0] == '1') {
			_i0 += 2; scanu(l); scanu(r); scanu(a); scanu(b);
			cnt = 0, t = b - a + 1, ++r, _ = 0; while (l < r) cnt += (unsigned) (h[l++] - a) < t;
			if (cnt > 999) _o[_o0 + 3] = cnt % 10 + '0', cnt /= 10, _o[_o0 + 2] = cnt % 10 + '0', cnt /= 10, _o[_o0 + 1] = cnt % 10 + '0', cnt /= 10, _o[_o0] = cnt + '0', _o0 += 4;
			else if (cnt > 99) _o[_o0 + 2] = cnt % 10 + '0', cnt /= 10, _o[_o0 + 1] = cnt % 10 + '0', cnt /= 10, _o[_o0] = cnt + '0', _o0 += 3;
			else if (cnt > 9) _o[_o0 + 1] = cnt % 10 + '0', cnt /= 10, _o[_o0] = cnt + '0', _o0 += 2;
			else _o[_o0] = cnt + '0', ++_o0;
		    _o[_o0++] = '\n';
		} else { _i0 += 2; scanu(a); scanu(b); h[a] = b; }
	}
	fwrite(_o, 1, _o0, stdout);
	return 0;
}
