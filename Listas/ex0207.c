# include <stdio.h>
# include <stdlib.h>

void main(){
    int saldo_inicial = 0, opt = 0, saldo, valor_operacao = 0;
    printf("Digite seu saldo: ");
    scanf("%d", &saldo_inicial);

    saldo = saldo_inicial;

    do{
        printf("\n----Menu principal----\n");
        printf("1. Deposito;\n");
        printf("2. Retirada;\n");
        printf("3. Fim;\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opt);
       
        if (opt == 1 || opt == 2){
            printf("\nDigite o valor da operacao: ");
            scanf("%d", &valor_operacao);
        }

        if (opt == 1)
            saldo += valor_operacao;
        
        if (opt == 2)
            saldo -= valor_operacao;
        
    }while (opt != 3);


    printf("\n\nSeu saldo final eh de: %d\n", saldo);

    if (saldo < 0)
        printf("CONTA ESTOURADA!\n\n");

    if (saldo == 0)
        printf("CONTA ZERADA!\n\n");

    if (saldo > 0)
        printf("CONTA PREFERENCIAL!\n\n");

    system("pause");
}