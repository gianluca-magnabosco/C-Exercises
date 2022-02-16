# include <stdio.h>
# include <stdlib.h>

void main(){
    int A,B,C,D,E;
    A = 5;
    A += 2;
    B = ++A;
    C = (2 * A + 3) % B;
    D = (B != C) && (A + B == 3 * C);
    E = A <= B ? A : C;
    printf("\nA 8 %d \nB 8 %d \nC 3 %d \nD 0 %d \nE 8 %d\n",A,B,C,D,E);
    system("pause");
}