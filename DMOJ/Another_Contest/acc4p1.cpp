#include <algorithm>

string f(int N)
{
    string res;
    do 
    {  
        res.push_back(N % 10 + '0');
    } while (N /= 10);
    
    reverse(res.begin(), res.end());
    return res;
}
