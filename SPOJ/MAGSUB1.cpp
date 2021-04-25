#include <iostream>
#include <string>

using namespace std;

string magical = "BCEGKMQSW";

int count_substr(string S, int N)
{
	int res = 0, count = 1;
	for (int i = 0; i < N; i++)
	{
		if (magical.find(S[i]) != string::npos)
		{
			res += count * (N - i);
			count = 1;
		}
		else ++count;
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	string S;
	while (T--)
	{
		cin >> N >> S;
		cout << count_substr(S, N) << '\n';
	}
	return 0;
}
