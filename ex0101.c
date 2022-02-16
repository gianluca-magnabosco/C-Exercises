# include <stdio.h>
# include <stdlib.h>

void main(){
    int A,B,C,D,E,F;
    A = 5;
    A += 2;
    B = A++;
    C = (2 * A + 3) % B;
    D = (B != C) && (A + B == 3 * C);
    E = A <= B ? A : C;
    printf("\nA 8 %d \nB 7 %d \nC 5 %d \nD 1 %d \nE 5 %d\n",A,B,C,D,E);
    system("pause");
}