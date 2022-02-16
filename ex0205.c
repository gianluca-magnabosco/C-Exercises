# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

void main(){
    int nota1 = 0, nota2 = 0, notaopt = 0, media;
    char is_opt;
    printf("Digite sua nota na primeira avaliacao: ");
    scanf("%d", &nota1);

    printf("Digite sua nota na segunda prova: ");
    scanf("%d", &nota2);


    do{
        printf("Voce realizou a prova optativa? [s/n]: ");
        scanf("%*c%c", &is_opt);

        if (toupper(is_opt) == 'S'){
            printf("Digite sua nota na prova optativa: ");
            scanf("%d", &notaopt);
            break;
        }
        if (toupper(is_opt) == 'N'){
            notaopt = -1;
            break;
        }
    }while(toupper(is_opt) != ('S' || 'N'));

    if(notaopt > (nota1 || nota2)){
        if (nota1 < notaopt){
            nota1 = notaopt;
        }else if (nota2 < notaopt)
            nota2 = notaopt;        
    }
    
    media = (nota1 + nota2) / 2;
    printf("Sua media eh: %d\n\n", media);

    system("pause");

}
