#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef complex<double> cd;

const double TAU = 6.28318530717958647692;
const cd one(1);

void scan_str(string& str)
{
	char c = '0';
	while ((c = getchar()) && (c != EOF && c != '\n')) str += c;
}

void fft(vector<cd>& vc, bool inv)
{
	int sz = vc.size(), half_sz = sz >> 1, bit;
	for (int i = 1, j = 0; i < sz; i++)
	{
		bit = half_sz;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if (i < j) swap(vc[i], vc[j]);
	}

	double ang;
	cd w, x, y;

	for (int i = 2, sign = inv ? -1 : 1; i <= sz; i <<= 1)
	{
		ang = TAU * sign / i;
		cd wm(cos(ang), sin(ang));
		for (int j = 0; j < sz; j += i)
		{
			w = one;
			for (int k = 0; k < i >> 1; k++)
			{
				x = vc[j + k], y = vc[j + k + (i >> 1)] * w;
				vc[j + k] = x + y;
				vc[j + k + (i >> 1)] = x - y;
				w *= wm;
			}
		}
	}

	if (inv) for (int i = 0; i < sz; i++) vc[i] /= sz;
}

vll mult(vll& va, vll& vb)
{
	int sz = 1, a_sz = va.size(), b_sz = vb.size();
	while (va.size() + vb.size() > sz) sz <<= 1;

	vector<cd> ca(va.begin(), va.end()), cb(vb.begin(), vb.end());
	ca.resize(sz), cb.resize(sz);

	fft(ca, false), fft(cb, false);
	for (int i = 0; i < sz; i++) ca[i] *= cb[i];

	fft(ca, true);

	vll res(sz + 1);
	for (int i = 0; i < sz; i++) res[i + 1] = round(ca[i].real());

	sz = a_sz + b_sz;
	res.resize(sz);

	ll carry = 0;
	for (int i = sz - 1; i > 0; i--)
	{
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}

	res[0] = carry;
	if (!res[0]) res.erase(res.begin());
	
	sz--;
	while (!res[sz] && sz) sz--;

	if (!sz) res.resize(1);
	
	for (ll r : res) cout << r;
	cout << "\n";
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	scan_str(a);
	scan_str(b);

	vll va(a.size()), vb(b.size());
	for (ll i = 0; i < va.size(); i++) va[i] = a[i] - '0';
	for (ll i = 0; i < vb.size(); i++) vb[i] = b[i] - '0';

	mult(va, vb);
	return 0;
}
