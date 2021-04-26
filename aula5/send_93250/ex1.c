# include<stdio.h>
# include<assert.h>

int nOp;// Contador de Operações ( Varíavel global)

int condEval(int array[], int n);

int main(void)
{
    int a[10] = {1,2,4,8,16,32,64,128,256,512};

    int len = 10;
    nOp = 0;

    printf("A sequência satisfaz a condição: %d (1 - verifica ; 0 - não verifica)\n", condEval(a, len));
    printf("Operações realizdas: %d\n", nOp);
    
}

int condEval(int *array, int n)
{
    assert (n > 2);
    
    nOp++;
    int r = array[1]/array[0]; //r = a[ 1 ] / a[ 0 ]

    for (int i = 2; i < n; i++)
    {
        nOp++;
        if (array[i] != array[i-1] * r)
        {
            return 0;
        }
    }
    return 1;
    
}