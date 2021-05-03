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
    unsigned int result = 0;
    assert(n>=0);

    if(n == 0 | n == 1 | n == 2){
        return 1;
    }else{
        result += funct(n-1);
        result += funct(n-2);

        for(int k = 0; k <= n-3;k++){
            nMul++;
            result += funct(k) * funct(n-3-k);
        }

        return result;
    }
}