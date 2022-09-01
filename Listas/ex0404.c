# include <stdio.h>
# include <stdlib.h>

void main(){
    int i = 5, j = 10;
    int *p, *q;

    p = &i;
    printf("%x \n", p);

    *q = &j;
    printf("%x, %x, %x\n", q, *q, &j);

    p = &*&i;
    printf("%x\n", p);   

    /*
        i = (*&)j;
        printf("%d\n", i);
    */

    i = *&j; 
    printf("%d, %d\n", i, j);

    i = *&*&j;
    printf("%d, %d\n", i, j);

    q = *p;
    printf("%d\n", q);

    i = (*p)++ + *q;
    printf("%d", i);
}

/* 
Se i e j são variáveis inteiras e p e q ponteiros para int, quais das
seguintes expressões de atribuição são ilegais?

a) p = &i; ---------> True -> p recebe endereço de i
b) *q = &j; --------> False -> o conteúdo de *q receberá o endereço de j -> ERRADO!
c) p = &*&i; -------> True -> p recebe o endereço de i
d) i = (*&)j; ------> False/True -> ?????????
e) i = *&j; --------> True -> i recebe valor de j;
f) i = *&*&j; ------> True -> i recebe valor de j;
g) q = *p; ---------> True -> q recebe valor de j(*p);
h) i=(*p)++ + *q; --> True -> i recebe valor de *p + *q + 1;
*/