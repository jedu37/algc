# include<stdio.h>
# include<assert.h>

int nComp;// Contador de Comparações ( Varíavel global)

int condFind(int array[], int n);

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    int len = 10;
    nComp = 0;

    printf("Quantidade de vezes que se satisfez a condição: %d \n", condFind(a, len));
    printf("Comparações realizdas: %d\n", nComp);
    
}

int condFind(int *array, int n)
{
    assert (n > 2);
    int oc = 0; // Número de Ocurrências da condição: 
                //array [i] = array [i – 1] + array [i + 1], para 0 < i < (n – 1) 
    nComp = 0;

    for (int i = 1; i < (n - 1); i++)
    {
        nComp++;
        if (array[i] == array[i-1] + array[i+1])
        {
            oc++;
        }
    }
    return oc;
    
}