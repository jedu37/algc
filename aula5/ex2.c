# include<stdio.h>
# include<assert.h>

int nComp;// Contador de Comparações ( Varíavel global)
int nShift;// Contador de Deslocamentos ( Varíavel global)

void dupeElem(int array[], int *n);
void printArray(int array[], int n);

int main(void)
{
    int a[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int len = 10;
    nComp = 0;
    nShift = 0;

    dupeElem(a,&len);

    printf("Comparações realizdas: %d\n", nComp);
    printf("Deslocamentos realizdas: %d\n", nShift);
    printArray(a,len);
    
}

void dupeElem(int *array, int *n)
{       
    int s = *n;
    assert(s > 1);
    // Array Processing
    for (int i = 0; i < s; i++)
    {
        for ( int j = i+1 ; j < s;)
        {
            nComp++;
            if((array[j] % array[i]) == 0){
                nShift++;
                
                for(int k = j; k < s; k++){
                    array[k] = array[k+1];
                }

                s--; // Retira o Valor
            }else{
                if(array[i] % array[j] == 0){
                    nShift++;

                    for(int k = j; k < s; k++){
                        array[k] = array[k+1];
                    }
                    s--;
                }else{
                    j++;
                }
            }
        }
    }

    *n = s;
}

void printArray(int array[], int n){
    printf("Array : {");

    for(int i = 0; i < n; i++){
        if( array[i] == 0){
            break;
        }

        printf("%d,",array[i]);

    }
    printf("}\n");
}
