# include <stdio.h>
# include <stdlib.h>

int contador = 0, i = 0, j = 0, nota = 0, num_aluno[9], media_aluno[9];
char questoes[9][7], gabarito[7];

void main(){


    printf("Digite o gabarito da prova: ");
    for (i = 0; i < 8; i++){
        printf("Questão %d: ", i+1);
        scanf("%c", gabarito[i]);
    }

    for (j = 0; j < 10; j++){
        printf("Digite o numero do aluno: ");
        scanf("%d", num_aluno[j]);
    
        printf("Digite o gabarito do aluno %d: ", num_aluno[j]);
        for (i = 0; i < 8; i++){
            printf("\nQuestão %d: ", i+1);
            scanf("%c", questoes[j][i]);
            if (questoes[j][i] == gabarito[i]){
                nota++;
                
                if (questoes[j][2] || questoes[j][7]){
                    nota++;
                }
            }
        
        media_aluno[j] = nota;
        nota = 0;
        }
    }

    for (i = 0; i < 9; i++){
        printf("Media do aluno %d: %d", num_aluno[i], media_aluno[i]);
    }
}