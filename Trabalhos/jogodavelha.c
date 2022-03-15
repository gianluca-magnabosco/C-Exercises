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
    int num_jogador = 0;
    int ganhou = 0;
    int i = 0;

    opcao_selecionada = menu();

    if (opcao_selecionada == 1) {
        if (nivel == 1){
            // bot basico
            escolha_simb(&jog1, &jog2);
            inicializa_velha();
        }
        if (nivel == 2){
            // bot intermediario
            escolha_simb(&jog1, &jog2);
            inicializa_velha();
        }
        if (nivel == 3){
            // bot avancado
            escolha_simb(&jog1, &jog2);
            inicializa_velha();
        }
    }

    if (opcao_selecionada == 2) {
        escolha_simb(&jog1, &jog2);
        inicializa_velha();

        do{
            i++;
            if (i % 2 == 0){
                jog = jog1;
                num_jogador = 1;
            } else {
                jog = jog2;
                num_jogador = 2;
            }
            
            printf("\nJogada do jogador %d (%c)", num_jogador, jog);
            printf("\nDigite a posicao correspondente a sua jogada (formato: [linha coluna]): ");
            scanf("%d %d", &lin, &col);

            printf("%d %d\n", lin, col);


            // jogada usuario
            int aux = jogada_usuario(lin, col, jog);
            //printf("%d", aux);
            
            ///////// montar as mensagens de erro de acordo com o numero retornado pela funçao jogada_usuario



            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    printf("%c", tabuleiro[i][j]);
                    if (j == 2){
                        printf("\n");
                    }
                }
            }
        

            ganhou = verifica_ganhador(jog);

        } while (ganhou != 1);

        if(ganhou == 1){
            printf("\n\n\nParabens jogador %d, voce venceu!!!", num_jogador);
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
            break;
        }

        if ((opcao != 1) && (opcao != 2)){
            printf("\nDigite uma opcao valida!\n\n");
        }

    } while ((opcao != 1) || (opcao != 2));
    
    // retorno da funcao menu
    return opcao;
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
    
    if ((tabuleiro[lin][col] == 'O') || (tabuleiro[lin][col] == 'X')){
        return 2;
    }  

    if ((lin > 2) || (lin < 0) || (col < 0) || (col > 2)){
        return 1;
    }

    if ((lin < 3) && (col < 3) && (tabuleiro[lin][col] != 'O') && (tabuleiro[lin][col] != 'X')){
        tabuleiro[lin][col] = jog;   
        return 0;  
    }
}


int verifica_ganhador(char jog){

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((tabuleiro[i][j] == jog) && (tabuleiro[i][j+1] == jog) && (tabuleiro[i][j+2] == jog)){
                return 1;
            }
            if ((tabuleiro[i][j] == jog) && (tabuleiro[i+1][j] == jog) && (tabuleiro[i+2][j] == jog)){
                return 1;
            }
            if ((tabuleiro[i][j] == jog) && (tabuleiro[i+1][j+1] == jog) && (tabuleiro[i+2][j+2] == jog)){
                return 1;
            }
        }
    } 

    return 0;
}