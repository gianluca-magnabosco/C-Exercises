# include <stdlib.h>
# include <stdio.h>


void main(){
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0, input = 0;


    scanf("%d", &input);
    for (i = 0; i < 10; i++){
        if (input == vetor[i]){
            printf("%d", i);
        }
    }

    

}