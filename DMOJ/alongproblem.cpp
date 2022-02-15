#include <bits/stdc++.h>

using namespace std;

/* FUNCTION 1 */
int divide(int a, int b) {
	return a / b;
}
/* END FUNCTION 1 */

/* FUNCTION 2 */
int lps[100];
int count_occurrences(string s, string p) {
	int slen = s.size(), plen = p.size();
	memset(lps, 0, plen); lps[0] = -1;
	for (int i = 0, j = -1; i < plen; i++, j++, lps[i] = j)
		while (j >= 0 && p[i] != p[j]) j = lps[j];
	int res = 0;
	for (int i = 0, j = 0; i < slen; i++, j++) {
		while (j >= 0 && s[i] != p[j]) j = lps[j];
		if (j == plen - 1) ++res;
	}
	return res;
}
/* END FUNCTION 2 */

/* FUNCTION 3 */
vector<int> sort_array(vector<int> arr) {
	sort(arr.begin(), arr.end());
	return arr;
}
/* END FUNCTION 3 */

/* FUNCTION 4 */
int psa[1001];
int max_size_k(vector<int> arr, int k) {
	int alen = arr.size(), mx = 0;
	for (int i = 1; i <= alen; i++) psa[i] = psa[i - 1] + arr[i - 1];
	for (int i = k; i <= alen; i++) mx = max(mx, psa[i] - psa[i - k]);
	return mx;
}
/* END FUNCTION 4 */

/* FUNCTION 5 */
char find_upper(char ch) {
	return toupper(ch);
}
/* END FUNCTION 5 */

/* FUNCTION 6 */
bool prime[1001] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0};
bool is_prime(int n) {
	return prime[n];
}
/* END FUNCTION 6 */

/* FUNCTION 7 */
bool has[101];
int distinct_integers(vector<int> arr) {
	memset(has, 0, 101);
	for (int x : arr) has[x] = true;
	int res = 0;
	for (int i = 1; i <= 100; i++) res += has[i];
	return res;
}
/* END FUNCTION 7 */

/* FUNCTION 8 */
bool is_inside(int x, int y, int rx, int ry, int w, int h) {
	return x <= rx && rx <= x + w && y <= ry && ry <= y + h;
}
/* END FUNCTION 8 */

/* FUNCTION 9 */
bool is_even(int n) {
	return (n & 1) == 0;
}
/* END FUNCTION 9 */

/* FUNCTION 10 */
bool is_bit_on(int bit, int num) {
	return (num >> bit) & 1;
}
/* END FUNCTION 10 */

/* FUNCTION 11 */
int freq[10];
int create_max(vector<int> dig) {
	for (int x : dig) ++freq[x];
	int res = 0;
	for (int i = 9; i >= 0; i--)
		while (freq[i]) res = res * 10 + i, freq[i]--;
	return res;
}
/* END FUNCTION 11 */

/* FUNCTION 12 */
int factorial(int n, int m) {
	int res = 1;
	for (int i = 1; i <= n; i++) res = 1LL * res * i % m;
	return res;
}
/* END FUNCTION 12 */

/* FUNCTION 13 */
bool should_feed(int h, int m, int th) {
	return h * m >= th;
}
/* END FUNCTION 13 */

/* FUNCTION 14 */
pair<int, int> lowest_terms(int num, int denom) {
	int g = __gcd(num, denom);
	return {num / g, denom / g};
}
/* END FUNCTION 14 */

/* FUNCTION 15 */
int find_sum(int n) {
	return (n * (n + 1)) >> 1;
}
/* END FUNCTION 15 */

/* FUNCTION 16 */
string tp[11] = {"", "max, do", "dhruv, fold", "abayomi, open", "snjezana, write", "yuxuan, close", "mohamed, move", "scarlet, crush", "anastasia, tear", "aksana, press", "alejandro, cut"};
string find_type(int type) {
	return tp[type];
}
/* END FUNCTION 16 */

/* FUNCTION 17 */
string largest_lex(vector<string> arr) {
	string res;
	for (string s : arr)
		if (s.compare(res) > 0)
			res = s;
	return res;
}
/* END FUNCTION 17 */

/* FUNCTION 18 */
vector<int> add_colours(vector<int> c1, vector<int> c2) {
	return {min(255, c1[0] + c2[0]), min(255, c1[1] + c2[1]), min(255, c1[2] + c2[2])};
}
/* END FUNCTION 18 */

/* FUNCTION 19 */
string remove_occurrences(string s, string p) {
	regex pat(p);
	return regex_replace(s, pat, "");
}
/* END FUNCTION 19 */

/* FUNCTION 20 */
bool AC() {
	return true;
}
/* END FUNCTION 20 */

int main() {
	assert(divide(5, 2) == 2);
	assert(count_occurrences("babab", "bab") == 2);
	vector<int> v00 = {5, 3, 6000, 20};
	vector<int> v01 = {3, 5, 20, 6000};
	assert(sort_array(v00) == v01);
	vector<int> v10 = {5, 6, 100, 20, 5};
	assert(max_size_k(v10, 2) == 120);
	assert(find_upper('c') == 'C');
	assert(is_prime(107) == true);
	vector<int> v20 = {5, 100, 3, 20, 20, 5, 1};
	assert(distinct_integers(v20) == 5);
	assert(is_inside(1, 1, 5, 5, 4, 4) == true);
	assert(is_even(5) == false);
	assert(is_bit_on(2, 4) == true);
	vector<int> v30 = {0, 0, 9, 3, 9};
	assert(create_max(v30) == 99300);
	assert(factorial(50, 100007) == 34694);
	assert(should_feed(1, 1, 1) == true);
	assert(lowest_terms(5, 15) == make_pair(1, 3));
	assert(find_sum(5) == 15);
	assert(find_type(6) == "mohamed, move");
	vector<string> v40 = {"abc", "bca", "dcd", "cba"};
	assert(largest_lex(v40) == "dcd");
	vector<int> v50 = {255, 50, 125};
	vector<int> v51 = {255, 0, 100};
	vector<int> v52 = {255, 50, 225};
	assert(add_colours(v50, v51) == v52);
	assert(remove_occurrences("abcabcab", "abcab") == "cab");
	assert(AC() == true);
	return 0;
}