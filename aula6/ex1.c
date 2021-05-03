# include<stdio.h>
# include<assert.h>
unsigned int funct1(unsigned int n);
unsigned int funct2(unsigned int n);
unsigned int funct3(unsigned int n);

int nRec;// Contador de Chamadas Recursivas
int main(void){
    unsigned int result;
    printf("Resultados\n n|T1(n)| NOp1|T2(n)| NOp2|T3(n)| NOp3\n");
    for(int i = 0; i<29;i++){
        printf("%2d|", i);
        nRec = 0;
        result = funct1(i);
        printf("%5d|%5d|",result,nRec);
        nRec = 0;
        result = funct2(i);
        printf("%5d|%5d|",result,nRec);
        nRec = 0;
        result = funct3(i);
        printf("%5d|%5d\n",result,nRec);

    }
}

unsigned int funct1(unsigned int n){
    assert(n >= 0);
    nRec++;

    if(n == 0){
        return 0;
    }
    else{
        return funct1(n/4) + n;
    }
}

unsigned int funct2(unsigned int n){ 
    assert(n >= 0);
    nRec++;

    if(n < 4){
        return n;
    }
    else{
        return funct2(n/4) + funct2((n+3)/4 ) + n;
    }
}

unsigned int funct3(unsigned int n){
    assert(n >= 0);
    nRec++;

    if(n < 4){
        return n;
    }
    else if( n%4==0){
        return 2*funct3(n/4) + n;
    }else{
        return funct3(n/4) + funct3((n+3)/4) + n;
    }
}