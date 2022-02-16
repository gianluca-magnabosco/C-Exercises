# include <stdio.h>
# include <stdlib.h>


void main(){
    int x;
    printf("Digite um numero inteiro entre 1 e 5: ");
    scanf("%d", &x);
    switch (x){
        case 1:
            printf("Valor de x: %d \n", x);
            break;
        case 2:
            printf("Valor do dobro de %d: %d \n", x, 2*x);
            break;
        case 3:
            printf("Valor do triplo de %d: %d \n", x, 3*x);
            break;
        case 4:
            printf("Valor do quadruplo de %d: %d \n", x, 4*x);
            break;
        default:
            printf("Valor digitado: %d \n", x);
    }
    system("pause");
}
