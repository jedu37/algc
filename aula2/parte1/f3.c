unsigned int f3(unsigned int);

int main(void){

    for(int i = 1; i <= 15 ;i++){

        

        unsigned int r = f3( (unsigned) i); 
        
        printf("f3(%d)= %d \n\n",i,r);

    }
    return 0;
}

unsigned int f3 (unsigned int n)
{
    unsigned int i, j, r = 0;
    int num_ops = 0;
    
    for (i = 1; i <= n; i++){
        for (j = i; j <= n; j++){
            r += j;
            num_ops++;
        }
    }

    printf( "f3 made with %d operations \n",num_ops);
    return r;
}
