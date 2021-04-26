void init_array(int *a,int n);
int factoriao(int n, int *a);

int main(void){
    int fact[10];

    init_array(fact ,10);
    return 0;
    printf("FactorioesS:\n");
    for(int i = 1; i < 10000000; i++){
        if(i == factoriao(i,fact)){
            printf("-> %d\n",i);
        }
    }
}

void init_array(int *a,int n){
    for(int i = 0; i<n; i++){
        if(i==0){
            a[i] = 1;
        }
        else{
            a[i] = i*a[i-1];
        }
    }
}

