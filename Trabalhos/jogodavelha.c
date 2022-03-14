# include <stdio.h>
# include <stdlib.h>

int jogada_usuario(int lin, int col, char jog);
void jogada_computador(char jog, int nivel);
int menu();
void escolha_simb(char *jog1, char *jog2);
void inicializa_velha();
int verifica_ganhador(char jog);

char tabuleiro[3][3];
int opcao = 0;
int nivel = 0;
char jog1 = 'O';
char jog2 = 'X';
char jog = ' ';


void main(){
    int opcao_selecionada;
    int lin = 0;
    int col = 0;
    opcao_selecionada = menu();
    nivel = opcao_selecionada - opcao;

    if (opcao == 1){
        if (nivel == 1){
            // bot basico
        }
        if (nivel == 2){
            // bot intermediario
        }
        if (nivel == 3){
            // bot avancado
        }
    } else {
        printf("\nDigite a posicao correspondente a sua jogada (formato: [linha coluna]): ");
        scanf("%d %d", &lin, &col);

        printf("%d %d\n", lin, col);
        jog = 'O';
        jogada_usuario(lin, col, jog);
        // jogada usuario

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                printf("%c", tabuleiro[i][j]);
                if (j == 2){
                    printf("\n");
                }
        }
    }
    }
}

int menu(){
    // limpar tela
    system("cls");

    do{
        // inicio menu
        printf("\n\n-----------MENU PRINCIPAL-----------\n");
        printf("1- Jogar contra computador\n");
        printf("2- Jogar contra humano\n");
        printf("\nSelecione a opcao desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1){
            do{
                printf("\n\nEscolhido: Jogar contra computador!\n\n");
                printf("Niveis de dificuldade do computador:\n");
                printf("1- Nivel basico\n");
                printf("2- Nivel intermediario\n");
                printf("3- Nivel avancado\n");
                printf("Escolha o nivel de dificuldade do computador: ");
                scanf("%d", &nivel);


                if (nivel == 1){
                    printf("\nBot nivel basico\n");
                    break;
                }

                if (nivel == 2){
                    printf("\nBot nivel intermediario\n");
                    break;
                }

                if (nivel == 3){
                    printf("\nBot nivel avancado\n");
                    break;
                }

                if ((nivel != 1) && (nivel != 2) && (nivel != 3)){
                    printf("\nDigite uma opcao valida!\n\n");
                }


                
            } while ((nivel != 1) || (nivel != 2) || (nivel != 3));

            break;
        }

        if (opcao == 2){
            escolha_simb(&jog1, &jog2);
            // jogada usuario
            inicializa_velha();
            break;
        }

        if ((opcao != 1) && (opcao != 2)){
            printf("\nDigite uma opcao valida!\n\n");
        }

    } while ((opcao != 1) || (opcao != 2));
    
    // retorno da funcao menu
    return (opcao + nivel);
}

void inicializa_velha(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
            printf("%c", tabuleiro[i][j]);
        }
    }
}

void escolha_simb(char *jog1, char *jog2){
    int escolha = 0;
    do {
        printf("\n\nEscolha o simbolo desejado para cada jogador: \n");
        printf("1- Jogador 1 (X) vs Jogador 2 (O)\n");
        printf("2- Jogador 1 (O) vs Jogador 2 (X)\n");
        printf("Insira uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1){
            *jog1 = 'X';
            *jog2 = 'O';
            break;
        }

        if (escolha == 2){
            *jog1 = 'O';
            *jog2 = 'X';
            break;
        }

        if ((escolha != 1) && (escolha != 2)){
            printf("\nDigite uma opcao valida!\n\n");
        }

    } while ((escolha != 1) || (escolha != 2));
}


int jogada_usuario(int lin, int col, char jog){
    

    tabuleiro[lin][col] = jog;


}