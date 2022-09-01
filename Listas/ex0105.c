# include <stdio.h>
# include <stdlib.h>

void main(){
    int i,j,k,m,n,x,y,z;
    
    i = j = k = 3; 
    m = n = 5;
    //              i = 3; j = 3; k = 3; m = 5; n = 5;
    
    // 1
    i += ++j + 3 * k; // i = 16; j = 4; k = 3;
    printf("i = %d - 16; j = %d - 4; k = %d - 3\n", i, j, k);

    // 2
    k %= m = -((1 + n) / (2-n)); // COMO ERA: "k %= m = -(1 + n / (2-n));"
    printf("k = %d - 1; m = %d - 2; n = %d - 5\n", k, m, n);

    // 3
    1 + 3 * (n += 7 / 5) || 1 + 3 * (n += 7) / 5; // COMO ERA: "1 + 3 * n += 7 / 5;"
    
    x = 1 + 3 * (n += 7 / 5);
    printf("\n x = %d\n", x);
    
    y = 1 + 3 * ( n += 7 ) / 5;
    printf("\n y = %d\n", y);

    //
    // 4
    y = 1 + 3 * ( n += 7 ) / 5;
    printf("\n z = %d\n", z);

    system("pause");

}