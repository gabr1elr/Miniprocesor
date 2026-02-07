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
    int j=0,pozitie1,formeznr=0,nrbiti=0;
    printf("Operanzii: ");//nr test task3 352321536
    unsigned int v[N+1];
    for(int i=0; i<nrop; i++)
    {
        pozitie1=15;
        while(j<N+1)
        {
            int tmp=(int)(x[i]);
            if(formeznr!=0)//formeznr contine ramasitele de pe numarul precedent si nrbiti cati biti are acesta
            {
                int nevoiebiti=Dim-nrbiti,temporar;
                temporar=(tmp>>(15-nrbiti));
                formeznr=formeznr<<nevoiebiti;
                v[j]=formeznr|temporar;
                printf("%u ",v[j]);
                j++;
                pozitie1=15-nevoiebiti;
                formeznr=nrbiti=0;
            }
            else{
                pozitie1=pozitie1-Dim;
                if(pozitie1<0)//nu mai am de unde sa tai din acest numar
                {
                    pozitie1=pozitie1+Dim;
                    int mask=(1<<(pozitie1+1))-1;
                    formeznr=tmp&mask;
                    nrbiti=pozitie1+1;
                    pozitie1=15,i++;//trec pe urmatorul numar x[i]
                }
                else{
                    v[j]=getbits(tmp,Dim,pozitie1+1);
                    printf("%u ",v[j]);
                    j++;

                }
            }
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
