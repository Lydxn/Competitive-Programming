#include <stdio.h>

#define SZ (1 << 24)
#define OSZ (1 << 4)
#define scan(x) do{while((x=in[ii++])<'0'); for(x-='0'; '0'<=(_=in[ii++]); x=(x<<3)+(x<<1)+_-'0');}while(0)

char in[SZ], out[OSZ], _;
int rows[1001], cols[1001], ii, oi;

int main() 
{
    fread(in, 1, SZ, stdin);
    
    int r, c, q, x, y;
    scan(r); scan(c);
    
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (in[ii++] == 'X') rows[i] = cols[j] = 1;
        }
        ii++;
    }
    
    scan(q);
    while (q--)
    {
        scan(x); scan(y);
        out[oi++] = rows[y] || cols[x] ? 'Y': 'N';
        out[oi++] = '\n';
    }
    
    fwrite(out, 1, oi, stdout);
    return 0;
}
