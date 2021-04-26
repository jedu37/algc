unsigned int f1(unsigned int);

int main(void){

    for(int i = 1; i <= 15 ;i++){

        

        unsigned int r = f1( (unsigned) i); 
        
        printf("f1(%d)= %d \n\n",i,r);

    }
    return 0;
}

unsigned int f1 (unsigned int n)
{
    unsigned int i, j, r = 0;
    int num_ops = 0;

    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            r += 1;
            num_ops++;
        }
    }

    printf( "f1 made with %d operations \n",num_ops);

    return r;
}