# include <stdio.h>
# include <stdlib.h>

void main(){
    int x = 0, y = 0, z = 0, i = 0, sum = 0, mult = 1;
    do{
    printf("Digite o valor de X: ");
    scanf("%d", &x);

    printf("Digite o valor de Y: ");
    scanf("%d", &y);
    if (x > y){
        printf("X deve ser menor do que Y!\n\n");
    }
    }while(x > y);

    z = y - x;
    
    for(i=x; i<=y; i++){
        if (i % 2 == 0){
            sum += i;
        }else{
            mult *= i;
        }
    }
    printf("\nSoma dos numeros pares: %d\n", sum);
    printf("Multiplicacao dos numeros impares: %d\n\n", mult);


    system("pause");
}