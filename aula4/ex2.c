#include<stdio.h>
#include<assert.h>

int nComp;// Contador de Comparações ( Varíavel global)

int condFind(int *array, int length);

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int len = 10;
    nComp = 0;

    printf("Quantidade de vezes que se satisfez a condição: %d \n", condFind(a, len));
    printf("Comparações realizdas: %d\n", nComp);
}

int condFind(int *array, int n)
{
    assert (n > 2);
    int oc = 0; // Número de Ocurrências da condição: 
                //array [k] = array [i] + array [j], para i < j < k
    nComp = 0;

    for (int k = 2; k < n; k++)
    {
        for (int j = 1; j < k; j++)
        {
            for (int i = 0; i < j; i++)
            {
                nComp++;
                if (array [k] == array [i] + array [j])
                {
                    oc++;
                }
            }
        }
    }

    return oc;

}