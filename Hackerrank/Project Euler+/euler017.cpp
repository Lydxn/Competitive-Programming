#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> res;

void number_to_words(ll N)
{
    if (N < 20) res.push_back(ones[N]);
    else if (N < 100)
    {
        res.push_back(tens[N / 10]);
        number_to_words(N % 10);
    }
    else if (N < 1000)
    {
        number_to_words(N / 100);
        res.push_back("Hundred");
        number_to_words(N % 100);
    }
    else if (N < 1000000)
    {
        number_to_words(N / 1000);
        res.push_back("Thousand");
        number_to_words(N % 1000);
    }
    else if (N < 1000000000)
    {
        number_to_words(N / 1000000);
        res.push_back("Million");
        number_to_words(N % 1000000);
    }
    else
    {
        number_to_words(N / 1000000000);
        res.push_back("Billion");
        number_to_words(N % 1000000000);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    ll N;
    while (T--)
    {
        cin >> N;
        if (N == 0) cout << "Zero\n";
        else
        {
            res.clear();
            number_to_words(N);

            for (auto& s : res)
            {
                if (s == "") continue;
                cout << s << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
