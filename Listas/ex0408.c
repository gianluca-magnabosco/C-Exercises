/*
Supor a declaração: int mat[4], *p, x; Quais expressões são válidas?
*/
# include <stdio.h> 
# include <stdlib.h>

void main(){
    int mat[4], *p, x;
    
    mat[0] = 0;

    p = mat;
    printf("%x\n", p);



    p = mat + 1; // Válida
    printf("%x\n", p); // Válida


    x = (*p)++; // Válida 
    printf("%d", x); // Válida
}





/*
Justifique:
a) p = mat + 1; --> True - pega o primeiro índice do vetor e adiciona 1 unidade (2 bytes como é integer);
b) p = mat++; ----> False - não rola incrementar o endereço de memória;
c) p = ++mat; ----> False - não rola incrementar o endereço de memória;
d) x = (*p)++; -> True - pega o valor do primeiro (ou segundo se considerar p = mat + 1) elemento do vetor e incrementa em 1;
*/