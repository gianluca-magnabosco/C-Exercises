# include <stdio.h>
# include <stdlib.h>


void main(){
    // Seja o seguinte trecho de programa:
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;
}

/*
Qual é o valor das seguintes expressões ?
a) p == &i; -----------> True (1)
b) *p - *q; -----------> -2
c) **&p; --------------> 3
d) 3* - (*p)/(*q)+7; --> 3 * - 3/(5)+7 = -9/13
*/