#include <bits/stdc++.h>

using namespace std;

char vowels[] = {'A', 'E', 'I', 'O', 'U', 'Y'};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int max_jump = 0, curr = 1;
    for (char c : s)
    {
        if (find(begin(vowels), end(vowels), c) == end(vowels)) ++curr;
        else curr = 1;
        max_jump = max(max_jump, curr);
    }
    
    cout << max_jump << '\n';
    return 0;
}
