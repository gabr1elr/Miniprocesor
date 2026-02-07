#include <stdio.h>
#include <stdlib.h>

unsigned int getbits(int nr, int k, int pos)
{
    return (((1 << k) - 1) & (nr >> pos));
}

int main()
{
    unsigned int inst, N, Dim;
    scanf("%u", &inst);
    N=getbits(inst, 3, 29) + 1;
    printf("%u ", N);

    int poz=27;

    unsigned int op[8];

    for(int i=0; i<N; i++)
    {
        op[i] = getbits(inst, 2, poz);
        switch(op[i])
        {
        case 0:
            printf("+ ");
            break;
        case 1:
            printf("- ");
            break;
        case 2:
            printf("* ");
            break;
        case 3:
            printf("/ ");
            break;
        default:
        }
        poz-=2;
    }
    poz+=2;//ma intorc la val de la ultima rulare
    Dim = getbits(inst, 4, poz-4) + 1;
    printf("%u ", Dim);
    return 0;
}
