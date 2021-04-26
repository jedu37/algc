#include<stdio.h>
int main ( void )
{
    char name[50];

    puts ( "What is your name?" );

    //fgets( name,50,stdin );
    scanf( "%[^\n]", name);

    printf( "Hello %s! \n",name);

    return 0;
}   