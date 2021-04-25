// Again, based off of VFMUL, so is quite slow.

#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

const double TAU = 6.28318530717958647692;

void fft(vector<complex<double>>& vc, bool inv)
{
	int sz = vc.size();
	if (sz == 1) return;

	vector<complex<double>> vca(sz >> 1), vcb(sz >> 1);
	for (int i = 0; i < sz >> 1; i++)
	{
		vca[i] = vc[i << 1];
		vcb[i] = vc[(i << 1) + 1];
	}

	fft(vca, inv);
	fft(vcb, inv);

	double ang = TAU / sz * (inv ? -1 : 1);
	complex<double> w(1), wm(cos(ang), sin(ang));

	complex<double> a, b;
	for (int i = 0; i < sz >> 1; i++)
	{
		a = vca[i], b = w * vcb[i];

		vc[i] = a + b;
		vc[i + (sz >> 1)] = a - b;
		w *= wm;
	}

	if (inv) for (int i = 0; i < sz; i++) vc[i] /= 2;
}

vector<ll> mult(vector<ll> & va, vector<ll> & vb)
{
	int sz = 1, a_sz = va.size(), b_sz = vb.size();
	while (a_sz + b_sz > sz) sz <<= 1;

	vector<complex<double>> ca(va.begin(), va.end()), cb(vb.begin(), vb.end());
	ca.resize(sz), cb.resize(sz);

	fft(ca, false), fft(cb, false);
	for (int i = 0; i < sz; i++)
	{
		ca[i] *= cb[i];
	}

	fft(ca, true);

	vector<ll> res(sz + 1);
	for (int i = 0; i < sz; i++)
	{
		res[i + 1] = round(ca[i].real());
	}

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
	if (!res[0]) res.erase(res.begin()), sz--;

	while (!res[--sz] && sz);
	if (!sz) res.resize(1);
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		vector<ll> va(a.size()), vb(b.size());

		for (ll j = 0; j < va.size(); j++) va[j] = a[j] - '0';
		for (ll j = 0; j < vb.size(); j++) vb[j] = b[j] - '0';

		vector<ll> res = mult(va, vb);
		for (ll r : res) cout << r;
		cout << "\n";
	}
	return 0;
}
