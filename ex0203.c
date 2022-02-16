# include <stdio.h>
# include <stdlib.h>


void main(){
    int i,j,num;
    float media,total;
    int vet[1000];
    i = 0;

    do{
        printf(" Insira um numero positivo: ");
        scanf("%d", &num);
        vet[i] = num;
        i++;
    }while(num >= 0);

    i -= 1;
    
    for(j=0; j<i; j++){
        total = total + vet[j];
    }

    media = total/i;
    printf("\n Media: %f \n\n",media);
    system("pause");

}