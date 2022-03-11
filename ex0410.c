/*
O que faz o seguinte programa quando executado?
*/


/*
# include <stdlib.h>
# include <stdio.h>

void main(){
    int vet[] = {4,9,12};
    int i, *ptr;

    ptr = vet;

    for(i = 0 ; i < 3 ; i++) 
        printf("%d, ",*ptr++); // incrementa o endereço de memoria do ponteiro 3x, mostrando o valor de cada elemento do vetor;
}
*/




# include <stdlib.h>
# include <stdio.h>

void main(){
    int vet[] = {4,9,12};
    int i, *ptr;

    ptr = vet;

    for(i = 0 ; i < 3 ; i++) 
        printf("%d, ",(*ptr)++); // incrementa o valor do primeiro indice do vetor 3x
}
