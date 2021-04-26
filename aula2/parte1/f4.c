unsigned int f4(unsigned int);

int main(void){

    for(int i = 1; i <= 15 ;i++){

        

        unsigned int r = f4( (unsigned) i); 
        
        printf("f4(%d)= %d \n\n",i,r);

    }
    return 0;
}

unsigned int f4(unsigned int n)
{
    unsigned int i, j, r = 0;
    int num_ops = 0;
    
    for (i = 1; i <= n; i++){
        for (j = i; j >= 1; j /= 10){
            r += i;
            num_ops++;
        }
    }

    printf( "f4 made with %d operations \n",num_ops);
    return r;
}