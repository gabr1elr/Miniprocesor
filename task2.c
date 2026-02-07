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
    printf("%u \n", Dim);
    int nrop=((N+1)*Dim)/16;
    if(((N+1)*Dim)%16!=0)
        nrop++;
    printf("Numere de introdus = %d \nIntroduceti numar: ",nrop);
    unsigned short x[nrop];
    for(int i=0; i<nrop; i++)
        scanf("%hu",&x[i]);
    int dimensiune=nrop*(16/Dim),j=0,z=0,cnt=16/Dim,cond2=0;
    printf("Operanzii: ");
    unsigned int v[dimensiune];
    for(int i=0; i<nrop; i++)
    {
        z=0;
        while(z<cnt)
        {
            int tmp=(int)(x[i]);
            v[j]=getbits(tmp,Dim,16-Dim-(z*Dim));
            if(cond2 >= N+1)
                v[j]=0;
            printf("%u ",v[j]);
            j++,z++;
        }
    }
    unsigned int rezultat=v[0];
    for(int i=0; i<N; i++)
    {
        switch(op[i])
        {
        case 0:
            rezultat=rezultat+v[i+1];
            break;
        case 1:
            rezultat=rezultat-v[i+1];
            break;
        case 2:
            rezultat=rezultat*v[i+1];
            break;
        case 3:
            rezultat=rezultat/v[i+1];
            break;
        default:
        }
    }
    printf("\nRezultatul este %u",rezultat);
    return 0;
}
