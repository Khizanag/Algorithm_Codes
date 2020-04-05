#include <stdio.h>

int d[1000001], f[100000];

int main()
{
    int k = 0, n, a, i;
    scanf("%d", &n);

    for(i = 2; i <= n; i++)
    {
        if(d[i] == 0)
        {
            d[i] = i;
            f[k++] = i;
        }

        for(a = 0; ; a++)
        {
            if ( (a == k) || ((i*f[a])>n) || (f[a]>d[i]) )
                break;
            d[i * f[a]] = f[a];
        }
    }
}
