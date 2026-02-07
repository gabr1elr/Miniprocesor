#include <stdio.h>
#include "math.h"

unsigned int getBits(unsigned int nr, int k, int pos) {
    return (((1 << k) - 1) & (nr >> (pos-1)));
}

int main() {
    unsigned int inst = 0;
    scanf("%u", &inst);
    unsigned int N = getBits(inst, 3, 30) + 1;
    // printf("%d ", N); // task1

    unsigned int operatii = getBits(inst, 2*N, 30-2*N);
    char op[16];
    int op_k = 0;

    for (int i = N-1; i >= 0; i--) {
        unsigned int tmp_operator = getBits(operatii, 2, 1+op_k);
        if (tmp_operator == 0)
            op[i] = '+';
        else if (tmp_operator == 1)
            op[i] = '-';
        else if (tmp_operator == 2)
            op[i] = '*';
        else if (tmp_operator == 3)
            op[i] = '/';
        op_k += 2;
    }

    // for (int i=0; i<op_k/2; i++) printf("%c ", op[i]); //task1

    unsigned int dim = getBits(inst, 4, 26-2*N) + 1;
    // printf("%u ", dim); // task1

    int numere = ((N+1) * dim) / 16;
    if (((N + 1) * dim) % 16 != 0) numere++;

    int v[128] = {0}, step = 0;
    for (int i = 0; i < numere; i++) {
        unsigned short int val;
        scanf("%hu", &val);

        for (int j = 16+step-1; val > 0; j--) {
            v[j] = val % 2;
            val /= 2;
        }
        step += 16;
    }

    int nr = 0, p = dim - 1, f[16] = {0};
    for (int i=0; i < dim; i++) {
        nr += v[i] * pow(2, p);
        p--;
    }
    f[0] = nr;
    int rez = nr, counter = 1;

    for (int i = dim; i <= 16*N; i += dim) {
        nr = 0, p = dim - 1;
        for (int j = i; j < i+dim; j++) {
            nr += v[j] * pow(2, p);
            p--;
        }
        f[counter] = nr;
        counter++;
    }

    for (int i = 1; i < counter; i++) {
        if (op[i-1] == '+')
            rez += f[i];
        else if (op[i-1] == '-')
            rez -= f[i];
        else if (op[i-1] == '*')
            rez *= f[i];
        else if (op[i-1] == '/' && f[i] != 0)
            rez /= f[i];
    }

    printf("%d", rez);
    printf("\n");
    return 0;
}