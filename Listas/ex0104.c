# include <stdio.h>
# include <stdlib.h>

void main(){
    int a,b,c = 5;

    a = b = 0; // a = 0; b = 0; c = 5;
    a = ++b + ++c; // a = 7; b = 1; c = 6;
    printf ("\n %d - 7 %d - 1 %d - 6", a, b, c);
    a = b++ + c++; // a = 7; b = 2; c = 7;
    printf ("\n %d - 7 %d - 2 %d - 7", a, b, c);
    a = ++b + c++; // a = 10; b = 3; c = 8;
    printf ("\n %d - 10 %d - 3 %d - 8", a, b, c);
    a = b-- + --c; // a = 10; b = 2; c = 7;
    printf ("\n %d - 10 %d - 2 %d - 7", a, b, c);
    a = ++c + c--; // a = 15; b = 2; c = 7;
    printf ("\n %d - 15 %d - 2 %d - 7", a, b, c);
    printf ("\n\n");
    system("pause");
}
