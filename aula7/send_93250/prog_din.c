# include<stdio.h>
# include<assert.h>
//Funções
unsigned int funct(unsigned int n);

//Variáveis Globais
int nMul;

//Função main
int main(void){
    printf("n,F(N),Mult(n)\n");
    for(int i = 0; i<=25; i++){
        nMul = 0;
        unsigned int res = funct(i);
        printf("%d,%d,%d\n",i,res,nMul);
    }
    return 0;
}

//Função recursiva
unsigned int funct(unsigned int n){
    unsigned int a[n+1];

    assert(n>=0);

    for(int i = 0; i<=n;i++){
        if(i == 0 | i == 1 | i == 2){
            a[i] = 1;
        }
        else{
            a[i] = a[i-1] + a[i-2];

            for(int k = 0; k <= i-3;k++){
                nMul++;
                a[i] += a[k] * a[i-3-k];
            }
        }
    }

    return a[n];
}
