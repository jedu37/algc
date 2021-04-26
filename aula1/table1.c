#include<stdio.h>
#include<math.h>

int main(void)
{
    double square_root;

    puts("Write a positive integer up to 30:");
    int num, square;
    scanf("%d", &num);

    puts(" n n*n sqrt(n)");
    puts("-- --- -----------------");

    for(int i = 1; i<num+1;i++){

        square_root = sqrt((float)i);
        square = i*i;

        printf("%2d %3d %1.16f\n",i, square, square_root);
    }

    return 0;
}