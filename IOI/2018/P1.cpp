#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int N) {
	string s, t;
	if (press("AB"))
		if (press("A")) s = "A", t = "BXY";
		else s = "B", t = "AXY";
	else
		if (press("X")) s = "X", t = "ABY";
		else s = "Y", t = "ABX";

	for (int i = 1; i < N - 1; i++)
		s += t[press(s + t[1] + s + t[2] + t[0] + s + t[2] + t[1] + s + t[2] + t[2]) - i];

	if (N == 1) return s;
	if (press(s + t[0]) == N) return s + t[0];
	if (press(s + t[1]) == N) return s + t[1];
	return s + t[2];
}
