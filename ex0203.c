# include <stdio.h>
# include <stdlib.h>


void main(){
    int i = 0, j, num;
    float media,sum = 0;

    do{
        printf(" Insira um numero positivo: ");
        scanf("%d", &num);
        if(num>=0){
            sum += num;
            i++;
        }
    }while(num >= 0);


    media = (sum/i);
    printf("\n Media: %f \n\n",media);
    system("pause");

}