long long f(string S) 
{ 
    long long D = 0, M = 0, O = 0, J = 0;
    for (int i = 0; i < S.length(); ++i)
    {
        switch (S[i])
        {
            case 'D':
                ++D;
                break;
            case 'M':
                M += D;
                break;
            case 'O':
                O += M;
                break;
            default:
                J += O;
                break;
        }
    }
    return J;
}
