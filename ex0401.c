# include <stdlib.h>
# include <stdio.h>

void main(){
    float a = 0.001;
    float b = 0.003;
    float c, *pa, *pb;
    pa = &a;
    pb = &b;
    c = 3 * (*pb - *pa); 
}

/*
Suponha que cada número ponto-flutuante ocupe 4 bytes de memória. Se o
valor assinalado a a começa no endereço 1130(hexadecimal) e o valor
assinalado a b começa no endereço 1134 e o valor assinalado a c começa
no endereço 1138, então:
a) Qual valor é assinalado a &a? -----------> 1130
b) Qual valor é assinalado a &b? -----------> 1134
c) Qual valor é assinalado a &c? -----------> 1138
d) Qual valor é assinalado a pa? -----------> 1130
e) Qual valor é representado por *pa? ------> 0.001
f) Qual valor é representado por &(*pa)? ---> 1130
g) Qual valor é assinalado a pb? -----------> 1144
h) Qual valor é representado por *pb? ------> 0.003 
i) Qual valor é assinalado a a -------------> 0.001
*/