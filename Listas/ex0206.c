# include <stdio.h>
# include <stdlib.h>

void main(){
    int soma_lote = 0, total_cheques = 0, sum_cheques, valor_cheques = 0, i;
    printf("Digite a soma do lote: ");
    scanf("%d", &soma_lote);

    printf("Digite o numero de cheques: ");
    scanf("%d", &total_cheques);

    for(i=1;i<=total_cheques; i++){
        printf("Digite o valor do cheque n %d: ", i);
        scanf("%d", &valor_cheques);
        sum_cheques += valor_cheques;
    }

    if (sum_cheques == soma_lote)
        printf("LOTE Ok\n\n");
    if (sum_cheques < soma_lote){
        printf("Diferenca negativa de %d\n\n", sum_cheques - soma_lote);
    }
    if (sum_cheques > soma_lote){
        printf("Diferenca positiva de %d\n\n", sum_cheques - soma_lote);
    }
    system("pause");
}