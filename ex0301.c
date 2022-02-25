# include <stdio.h>
# include <stdlib.h>

int contador = 0, i = 0, num_aluno = 0;
char questoes[7], gabarito[7];

void main(){


    printf("Digite o gabarito da prova: ");
    for (i = 0; i < 8; i++){
        printf("Questão %d: ", i+1);
        scanf("%d", gabarito[i]);
    }


    printf("Digite o numero do aluno: ");
    scanf("%d", num_aluno);
    
    
    printf("Digite o gabarito do aluno %d: ", num_aluno);
    for (i = 0; i < 8; i++){
        printf("\nQuestão %d: ", i+1);
        scanf("%s", questoes[i]);
    }
}