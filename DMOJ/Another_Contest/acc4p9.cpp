vector<int> f(int n)
{
    vector<int> res;
    const int MOD = 998244353;
    
    long long prod = 1;
    for (int i = 1; i <= n; i++) 
    {
        prod = (prod * i) % MOD;
        res.push_back(prod);
    }
    return res;
}
