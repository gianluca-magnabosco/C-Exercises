/*
O que fazem os seguintes programas?
*/




/*
# include <stdlib.h>
# include <stdio.h>

void main()
{
    int vet[] = {4,9,13};
    int i;
    for(i=0; i<3; i++)
        printf("%d, ",*(vet+i)); // mostra o valor de cada um dos elementos do vetor
}
*/






# include <stdlib.h>
# include <stdio.h>

void main()
{
    int vet[] = {4,9,13};
    int i;
    for(i=0; i<3; i++)
        printf("%x, ",vet+i); // mostra o endereço de memória de cada um dos elementos do vetor
}






/*
# include <stdlib.h>
# include <stdio.h>

void main()
{
    int vet[] = {4,9,13};
    int i;
    for(i=0; i<3; i++)
        printf("%x, ",vet+i); // mostra o endereço de memória de cada um dos elementos do vetor
}
*/
