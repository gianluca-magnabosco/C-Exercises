# include <stdio.h>
# include <stdlib.h>

void main(){
    int x,y,z;
    
    x = y = 10;
    printf(" Apos x = y = 10, x = %d - 10, y = %d - 10\n", x, y);

    z = ++x;
    printf(" Apos z = +xx, z = %d - 11, x = %d - 11\n", z, x);

    x = -x;
    printf(" Apos x = -x, x = %d - -11\n", x);

    y++;
    printf(" Apos y++, y = %d - 11\n", y);

    x = x + y - (z--);
    printf(" Apos x = x + y - (z--): \n");
    printf(" x = %d - -11\n y = %d - 11\n z = %d - 10\n", x, y, z);
    
    system("pause");
}