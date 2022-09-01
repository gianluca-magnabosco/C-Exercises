# include <stdio.h>
# include <stdlib.h>

// Qual será a saída deste programa supondo que i ocupa o endereço 4094 na memória?

void main() {
    int i=5, *p;
    p = &i;
    printf("%x \n %d \n %d \n %d \n %d \n", p, *p+2, **&p, 3* *p, **&p+4);
}

/* 
4094
7
5
15
9
*/