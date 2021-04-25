#include <bits/stdc++.h>

using namespace std;

vector<int> groups;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int w, consec = 0;
    string crossword;
    cin >> w >> crossword;
    
    for (char c : crossword + 'W')
    {
        if (c == 'B') consec++;
        else if (consec)
        {
            groups.push_back(consec);
            consec = 0;
        }
    }
    
    cout << groups.size() << '\n';
    for (int g : groups) cout << g << ' ';
    return 0;
}
